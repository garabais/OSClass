build: createdb insertdb readdb readbylastname updatedb

createdb: createdb.c student.h
	gcc createdb.c -o createdb
insertdb: insertdb.c student.h
	gcc insertdb.c -o insertdb
readdb: readdb.c student.h
	gcc readdb.c -o readdb
readbylastname: readbylastname.c student.h
	gcc readbylastname.c -o readbylastname
updatedb: updatedb.c student.h
	gcc updatedb.c -o updatedb
clean:
	rm createdb insertdb readdb readbylastname updatedb class.dat
