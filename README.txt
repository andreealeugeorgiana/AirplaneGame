task1:
Se introduce un pointer aux, o copie de tipul unsigned char a vectorului info, pentru
	a nu mai fi nevoie sa dereferentiem vectorul info la fiecare utilizare.
Cu ajutorul unui "for" se ia fiecare avion in parte si cu un "j" initializat cu 1, se parcurge
	vetctorul info. Cum j = 1, pentru a afisa linia avionului, se scade scade 1, iar pentru a
	afisa coloana, se aduna 1.
Mai apoi, se aduna inca 3 la valoarea curenta a lui j, adica 1, pentru a se trece la pozitia
	pe care se afla stocata directia avionului.
J-ul creste cu inca 1, si ajungem astfel la locul cu tipul si aeroportul avionului, pe care,
	pentru a le afisa, ne folosim de un for de la 0 la 4 si adunam valorile, alaturi de j,
	pentru a strabate portiunea pe care se afla tipul si aeroportul.
Adaugam lui j valoarea 4 si afisam ce se afla pe pozitia respectiva, adica viteza avionului.
Mai adaugam inca 5 la aloarea lui j pentru a ajunge pe pozitia 13, adica pozitia 0 a urmatorului
	avion daca este cazul.

task2:
Se introduce un pointer aux, o copie de tipul unsigned char a vectorului info, pentru
	a nu mai fi nevoie sa dereferentiem vectorul info la fiecare utilizare.
Parcurgem, mai apoi, matricea si daca se gaseste ca, coordonatele matricei coincid cu capul
	avionului, se verifica tipul avionului si directia in care se indreapta, pentru ca mai
	apoi, valorile matricei care corespund avionului, sa devina din ".", "*".

task3:
Functia "swap" are ca scop compararea a doua avioane. 
Ca date de intrare doi vectori de tip const void, in care se vor stoca informatiile despre
	cele doua avioane.
Astfel, se parcurg cei doi vectori pana se ajunge la zona ce corespunde
	tipului de avion (se aduna la valoarea curenta a acestora 2*sizeof(short int) pentru a 
	trece peste coordonate si sizeof(char) pentru a trece peste directie) si ceea ce se afla
	la adresa obtinuta (tipul) este atribuit unei variabile de tip unsigned char. Cele doua sunt
	comparate iar avioanele sunt ordonate crescator.
Daca avioanele sunt de acelasi tip, valorii curente a celor doi vectori ii este adunata un sizeof(char)
	pentru a trece peste tipul avionului.
Se copiaza, mai apoi, in doi vectori de tip char, 3 elemente din vectorii a si b, adica fix 
	aeroportul. In variabila x se stocheaza comparatia dintre acesti doi vectori de tip char,
	iar mai apoi, avioanele sunt ordonate descrescator.
Daca valoarea x este egala cu 0, (adica avioanele pleaca din acelasi aeroport), in vectorii
	a si b, se aduna 3*sizeof(char) pentru a trece peste zona cu aeroportul si a ajunge la
	cea in care este stocata viteza.
Analog se introduc doua variabile de tip unsigned int in care se dereferentiaza valoarea aflata
	la adresele celor doi vectori a si b, aceste doua variabile sunt comparate iar avioanele
	sunt ordonate crescator. 
In functia SolveTask3, se apeleaza functia qsort, iar mai apoi, se afiseaza avioanele exact 
	in task 1.

task4:
Analog ca la task-urile precedente, avem un o copie a vectorului 'info', un pointer de tip unsigned char 'aux'.
Cu ajutorul unui for, parcurgem fiecare avion.
Se introduce variabila ok = 1, adica se considera ca avionul este initial nelovit.
Mai apoi, se verifica tipul avionului si directia in care se indreapta.
Verificam, mai intai, daca intre aripi si coada avionului se afla un obstacol, mai apoi, daca in
	la coordonatele in care va ajunge capul avionului cand acesta va iesi de pe harta exista 
	un obstacol (pentru avioanele de tip 2, se verifica si daca zona in care va ajunge portiunea
	mai mica de dupa capul avionului, cand acesta se va afla la granita hartii are 
	obstacole sau nu, iar mai apoi, se verifica daca de la aripile avionului, pana la iesirea lui
	de pe harta se gaseste un obtacol. Daca un obstacol este gasit, ok ia valoarea 0, adica
	avionul este unul lovit.
Dupa aveasta verificare, daca avionul este nelovit, un contor 'cont' isi creste valoarea cu 1 pentru
	fiecare astfel de avion gasit.  