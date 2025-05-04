-- 코드를 입력하세요
SELECT FLAVOR
FROM FIRST_HALF 
ORDER BY TOTAL_ORDER DESC, 
CASE FLAVOR
    WHEN "chocolate" THEN 1
    WHEN "melon" THEN 2
    WHEN "white_chocolate" THEN 3
    WHEN "strawberry" THEN 4
    WHEN "mango" THEN 5
    WHEN "orange" THEN 6
    WHEN "pineapple" THEN 7
    WHEN "vanilla" THEN 8
    WHEN "caramel" THEN 9
    WHEN "peach" THEN 10
    WHEN "watermelon" THEN 11
    WHEN "mint_chocolate" THEN 12
END ASC;