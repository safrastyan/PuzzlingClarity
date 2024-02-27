1393. Capital Gain/Loss
# Write your MySQL query statement below

SELECT stock_name, sum(IF(operation="Buy", -price, price)) AS capital_gain_loss FROM stocks GROUP BY 1