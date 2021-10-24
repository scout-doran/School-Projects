local status err = pcall( function ()
    env = assert(require"luasql.mysql".mysql(), "Can't load library")
    -- connect to data source
    con = assert (env:connect("TTU", "root", "coursework"), "Can't connect to database")
    curr = assert (con:execute "SELECT first, lastname FROM students WHERE lastname LIKE 'D%';", "Error executing query")
end)

if not status then
    print("Error:" .. err)
end

row = curr:fetch({}, "a") -- the rows will be indexed by field names
while row do
    print(string.format("Firstname: %-10s, Lastname: %-15s", row.firstname, row.lastname))
    row = curr:fetch(row, "a") --reusing the table of results (possibly {} instead of row)
end
--Close everything
cur:close()
con:close()
env:close()