# Write your MySQL query statement below

Select a.Name as Employee
from
    Employee AS a, 
    Employee AS b
where 
    a.ManagerId=b.id
    and
    a.Salary>b.Salary;
         