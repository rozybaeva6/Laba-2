all: laba clean
laba: main.o allorderclear.o allorderwrite.o allcourierwrite.o allcourierclear.o courierdeleting.o oselect.o addorder.o osearchid.o runtime.o csearchid.o csearchname.o csearchphone.o addcourier.o 
	g++ main.o allorderclear.o allorderwrite.o allcourierwrite.o allcourierclear.o courierdeleting.o oselect.o addorder.o osearchid.o runtime.o csearchid.o csearchname.o csearchphone.o addcourier.o -o laba
main.o: main.cpp
	g++ -c main.cpp
allorderclear.o: allorderclear.cpp
	g++ -c allorderclear.cpp
allorderwrite.o: allorderwrite.cpp
	g++ -c allorderwrite.cpp
allcourierwrite.o: allcourierwrite.cpp
	g++ -c allcourierwrite.cpp
allcourierclear.o: allcourierclear.cpp
	g++ -c allcourierclear.cpp
courierdeleting.o: courierdeleting.cpp
	g++ -c courierdeleting.cpp
oselect.o: oselect.cpp
	g++ -c oselect.cpp
addorder.o: addorder.cpp
	g++ -c addorder.cpp
osearchid.o: osearchid.cpp
	g++ -c osearchid.cpp
runtime.o: runtime.cpp
	g++ -c runtime.cpp
csearchid.o: csearchid.cpp
	g++ -c csearchid.cpp
csearchname.o: csearchname.cpp
	g++ -c csearchname.cpp
csearchphone.o: csearchphone.cpp
	g++ -c csearchphone.cpp
addcourier.o: addcourier.cpp
	g++ -c addcourier.cpp
clean:
	rm -rf *.o 

