#!/usr/bin/env bash



MYSQL_USER=root
MYSQL_PASSWD=123
DATABASE=mysql_test
TABLE_NAME=test
function create_table() {
    local db_name=$1
    local table_name=$2
    mysql -u$MYSQL_USER -p$MYSQL_PASSWD -e "USE $db_name;CREATE TABLE IF NOT EXISTS $table_name (
                                            'id' UNSIGNED INT NOT NULL AUTO_INCREMENT,
                                            'name' VARCHAR(32) NOT NULL,
                                            'timestamp' TIMESTAP NOT NULL,
                                            PRIMARY KEY(id))"
}

create_table $DATABASE $TABLE_NAME
