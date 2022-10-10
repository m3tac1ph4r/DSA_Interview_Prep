# Write your MySQL query statement below
SELECT DISTINCT A.num as ConsecutiveNums FROM logs A,logs B,logs C
WHERE
A.id+1=B.id AND
B.id+1=C.id AND
A.num=B.num AND
B.num=C.num;