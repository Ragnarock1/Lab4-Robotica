# Lab4-Robotica

Componente
Arduino UNO (ATmega328P microcontroller)
1x LED RGB (pentru a semnaliza dacă cuvântul corect e scris greșit sau nu)
2x Butoane (pentru start/stop rundă și pentru selectarea dificultății)
5x Rezistoare (3x 220/330 ohm, 2x 1000 ohm)
Breadbord
Fire de legătură


Detalii tehnice
(1p) LED RGB - Indicator de stare:

În starea de repaus, LED-ul va avea culoarea albă.
La apăsarea butonului de start, LED-ul va clipi timp de 3 secunde, indicând o numărătoare inversă până la începerea rundei.
În timpul unei runde: LED-ul va fi verde dacă textul introdus este corect și va deveni roșu în caz de greșeală.
(1p) Butonul Start/Stop:

Modul de repaus: Dacă jocul este oprit, apăsarea butonului inițiază o nouă rundă după o numărătoare inversă de 3 secunde.
În timpul unei runde: Dacă runda este activă, apăsarea butonului o va opri imediat.
(1p) Butonul de dificultate:

Butonul de dificultate controlează viteza cu care apar cuvintele și poate fi folosit doar în starea de repaus.
La fiecare apăsare, dificultatea se schimbă ciclind între: (Easy, Medium, Hard).
La schimbarea dificultății, se trimite un mesaj prin serial: “Easy/Medium/Hard mode on!”.
Pentru gestionarea apăsărilor butoanelor, utilizați debouncing și întreruperi. Timerele vor fi folosite pentru a seta frecvența apariției cuvintelor. Un site util, care include și un videoclip despre utilizarea întreruperilor și timerelor în Arduino, este disponibil aici.
(3p) Generarea cuvintelor:

Se va crea un dicționar de cuvinte.
În timpul unei runde, cuvintele vor fi afișate în terminal într-o ordine aleatorie.
Dacă cuvântul curent a fost scris corect, un cuvânt nou va fi afișat imediat. Dacă nu, un nou cuvânt va apărea după intervalul de timp stabilit în funcție de dificultate.
Pentru a genera numere aleatorii, trebuie să folosiți funcția random().
(1p) Alte observații:

Timpul alocat pentru o rundă este de 30 de secunde.
La sfârșitul fiecărei runde, se va afișa în terminal câte cuvinte au fost scrise corect.
2.4 Flow
Jocul este în repaus. LED-ul RGB are culoarea albă.

Se alege dificultatea jocului folosind butonul de dificultate, iar în terminal va apărea “Easy/Medium/Hard mode on!”.

Se apasă butonul de start/stop.

LED-ul clipește timp de 3 secunde, iar în terminal se va afișa numărătoarea înversă: 3, 2, 1.

LED-ul devine verde și încep să apară cuvinte de tastat.

La tastarea corectă, următorul cuvânt apare imediat. Dacă nu se tasteaza cuvântul în timpul stabilit de dificultate, va apărea un nou cuvânt.

O greșeală face LED-ul să devină roșu. Pentru a corecta cuvântul, se va folosi tasta BackSpace.

Dupa 30 de secunde, runda se termină, iar în terminal se va afișa scorul: numărul total de cuvinte scrise corect.

Jocul se poate opri oricând cu butonul de start/stop.

Vă recomandăm să testați întâi funcționalitatea temei într-un simulator, apoi să realizați montajul fizic folosind componentele din kit-urile primite. Pentru simulare puteți folosi Wokwi sau TinkerCAD.
Pentru a fi notați, tema voastră TREBUIE să fie realizată fizic, nu doar în simulator!

2.5 Publicarea temei
(1p) Codul trebuie să fie încărcat pe github-ul personal, în repo-ul cursului, până în ziua laboratorului vostru din săptămâna 4-8 noiembrie.

Adăugați în fișierul README următoarele:

descrierea task-ului/ cerințele
componentele utilizate
poze ale setup-ului fizic
un link/video cu funcționalitatea montajului fizic
schema electrică (Wokwi, TinkerCAD etc.)
(2p) Începând cu această temă, va trebui să respectați un coding style. Acest lucru va face codul mai ușor de citit și de depanat. Nu este necesar să respectați fiecare regulă exact ca în documentul trimis, dar codul trebuie să fie lizibil și consecvent. Găsiți aici regulile pentru coding style.

#Schema 
https://ibb.co/prrxRGh

#Montaj 
https://ibb.co/197NFt9

#Video
https://youtube.com/shorts/ki7JWZVw9tA?si=p0p6EkG0TCl0A4iB
