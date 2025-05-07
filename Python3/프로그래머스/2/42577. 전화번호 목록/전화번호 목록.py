def solution(phone_book):
    set_phone_book = set(phone_book)
    phone_book.sort(key=len,reverse = True)
    minlen = len(phone_book[-1])
    # print(phone_book)
    for phone_number in phone_book:
        l = len(phone_number)
        for i in range(minlen,l,1):
            # print(phone_number[0:i])
            if phone_number[0:i] in set_phone_book:
                return False
        # print()
    return True