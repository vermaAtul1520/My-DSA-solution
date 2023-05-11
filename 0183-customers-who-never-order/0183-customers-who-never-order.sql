# Write your MySQL query statement below

# 1 method...

select name as Customers from 
  (  
      Customers c
      Left join Orders o
      On c.id= o.CustomerId
  )
where o.CustomerId IS NULL;


# Second method....

# select name as Customers 
# from customers
# where customers.id not in
#    (
#       select customerid from orders
#    );