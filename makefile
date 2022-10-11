run: all
	./sigbike

all:
	gcc -c -Wall modulovalidacoes/validacoes.c; gcc -c -Wall moduloveiculo/moduloveiculo.c; 
	gcc -c -Wall modulosore/modulosore.c; gcc -c -Wall moduloestoque/moduloestoque.c; 
	gcc -c -Wall modulocliente/modulocliente.c; gcc -c -Wall moduloaluguel/moduloaluguel.c;
	gcc -c -Wall moduloadministracao/moduloadministracao.c; gcc -c -Wall moduloprincipal.c; 
	gcc -o sigbike *.o;

clean:
	rm./*.o