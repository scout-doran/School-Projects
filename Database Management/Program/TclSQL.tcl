#look back at lect to see where missing bracket should be 
#use the format function
set firstname
set lastname
set credits
if{[catch {
    # load mysqltcl library
    package require mysqltcl
    # connect to the database
    set m [mysql::connect -user "root" - db "TTU" -password "coursework"]
    # submit the query and iterate over the results
    puts [format "| %-*s | %-*s | %-*s |" "Firstname" "Lastname" "Credits"]
    foreach {$firstname $lastname $credits}[ 
            mysql::sel $m{
                "SELECT firstname,lastname,credits, CASE WHEN credits >= 60 THEN 'YES' ELSE 'NO' END AS able_to_enroll FROM students"} -flatlist] {
        puts [format "| %*d | %*d | %*d |" "$firstname $lastname $credits"]
    }
    # close the connection
    mysql::close() $m
} {$firstname $lastname $credits}]} {
    puts {$firstname $lastname $credits}
}