-- Write your PostgreSQL query statement below
select  EmployeeUNI.unique_id, Employees.name 
    from Employees
    left join EmployeeUNI
    on EmployeeUNI.id = Employees.id


