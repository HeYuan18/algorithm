OBJS = stdfx.o rsa.o RSAtest.o

RSAtest: $(OBJS)
	gcc -o RSAtest $(OBJS) -lm -lcrypto
RSAtest.o: RSAtest.c
	gcc -c RSAtest.c
rsa.o: rsa.c
	gcc -c rsa.c rsa.h
stdfx.o: stdfx.c
	gcc -c stdfx.c stdfx.h
clean:
	rm $(OBJS) *.gch
