#!/usr/bin/env python 

import MySQLdb as mdb
conn = mdb.connect(host='127.0.0.1', port=3306, user='root',
		passwd='Caomende.3', db='mysql', charset='utf8')

cursor = conn.cursor()
try:
	DB_NAME = 'test'
	cursor.execute('DROP DATABASE IF EXISTS %s' %DB_NAME)
	cursor.execute('CREATE DATABASE IF NOT EXISTS %s' %DB_NAME)
	conn.select_db(DB_NAME)

	TABLE_NAME = 'user'
	cursor.execute('CREATE TABLE %s(id int, name varchar(30))' %TABLE_NAME)
	#sql = 'INSERT INTO user values("%d", "%s")' %(1, "jack")
	value = [2, 'John']
	cursor.execute('INSERT INTO user values(%s, %s)', value)
	

	conn.commit()

except:
	import traceback
	traceback.print_exc()
finally:
	count = cursor.execute('select * from %s' %TABLE_NAME)
	result = cursor.fetchone()
	print 'total records: %d' %count 
	print 'total records:', cursor.rowcount
	print 'id: %s, name: %s' %(result[0], result[1])
	cursor.close()
	
