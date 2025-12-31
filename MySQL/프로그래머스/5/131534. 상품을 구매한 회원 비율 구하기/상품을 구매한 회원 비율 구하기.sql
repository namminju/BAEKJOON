SELECT
    ym.YEAR,
    ym.MONTH,
    ym.PURCHASED_USERS,
    round(ym.PURCHASED_USERS / t.total_users, 1) AS PURCHASED_RATIO
FROM (
    SELECT
        YEAR(s.sales_date) AS YEAR,
        MONTH(s.sales_date) AS MONTH,
        COUNT(DISTINCT s.user_id) AS PURCHASED_USERS
    FROM ONLINE_SALE s
    JOIN USER_INFO u
      ON u.user_id = s.user_id
     AND YEAR(u.joined) = 2021
    GROUP BY YEAR(s.sales_date), MONTH(s.sales_date)
) ym
CROSS JOIN (
    SELECT COUNT(*) AS total_users
    FROM USER_INFO
    WHERE YEAR(joined) = 2021
) t
ORDER BY ym.YEAR, ym.MONTH;
