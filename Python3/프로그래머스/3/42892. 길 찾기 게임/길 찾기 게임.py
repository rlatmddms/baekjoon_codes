import sys
sys.setrecursionlimit(10000)
def solution(nodeinfo):
    length = len(nodeinfo)
    xlimit = 0;
    xminlimit = 999999999;
    for i in nodeinfo:
        if i[0] > xlimit:
            xlimit = i[0]
        if i[0] < xminlimit:
            xminlimit = i[0]
    for i in range(length):
        nodeinfo[i].append(i+1);
    nodeinfo.sort(key = lambda x : (-x[1],x[0]))
    tree = [[-1,-1] for _ in range(length+1)]
    # print(nodeinfo)
    depth = set();
    tmp = 0
    depth_nodeinfo = []
    tmparr = [nodeinfo[0]]
    depth.add(nodeinfo[0][1])
    nodeinfo[0][1] = 0
    for i in range(1,length):
        if(nodeinfo[i][1] in depth):
            nodeinfo[i][1] = tmp
            tmparr.append(nodeinfo[i])
            continue;
        tmp+=1
        depth.add(nodeinfo[i][1])
        nodeinfo[i][1] = tmp
        depth_nodeinfo.append(tmparr)
        tmparr = []
        tmparr.append(nodeinfo[i])
    depth_nodeinfo.append(tmparr)    
    depth = len(depth)
    main_root = nodeinfo[0]
    # print(depth_nodeinfo)
    def make_node(xl1,xl2,root):
        if root[1] >= depth-1 or xl1 < xminlimit or xl2 > xlimit: return;
        childs = [child_node for child_node in depth_nodeinfo[root[1]+1] if child_node[0] <= xl2 and child_node[0] >= xl1] 
        for idx,child in enumerate(childs):
            tree[root[2]][idx] = child[2]
            if child[0] > root[0]:
                make_node(root[0]+1,xl2,child)
            else:
                make_node(xl1,root[0]-1,child)
    make_node(xminlimit,xlimit,main_root)
    # previsit = [0]*(length+1)
    # postvisit = [0]*(length+1)
    preoder_arr = []
    postoder_arr = []
    def preoder(n):
        if n == -1:
            return;
        preoder_arr.append(n)
        # previsit[n] = 1
        preoder(tree[n][0])
        preoder(tree[n][1])
        
    def postoder(n):
        if n == -1:
            return;
        postoder(tree[n][0])
        postoder(tree[n][1])
        postoder_arr.append(n)
        # postvisit[n] = 1
    preoder(main_root[2])
    postoder(main_root[2])
    # return tree
    return [preoder_arr,postoder_arr]