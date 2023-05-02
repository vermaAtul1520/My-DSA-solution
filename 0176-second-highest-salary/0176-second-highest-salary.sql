# Write your MySQL query statement below

# select salary as SecondHighestSalary from Employee
# order by SecondHighestSalary desc limit 1,1;

SELECT IFNULL((SELECT DISTINCT Salary
	             FROM Employee 
				 ORDER BY Salary DESC 
				 LIMIT 1,1),NULL) AS SecondHighestSalary