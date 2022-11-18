all: compile run
	

# main.o Converter.o Content.o StringMethod.o SatirListesi.o YoneticiListesi.o tabBar.o YLB.o SLB.o LocationArrow.o Actions.o
#22. satirda problemim var

#g++ -I ./include/list/ -I ./include/other/ -I ./include/ui/ListBuilders/ -I ./include/ui/locationArrow/ -I ./include/ui/tabBar/ -o ./bin/main ./lib/SatirListesiNode.o ./lib/YoneticiListesiNode.o ./lib/SatirListesi.o ./lib/YoneticiListesi.o ./lib/Actions.o ./lib/Content.o ./lib/Converter.o ./lib/StringMethod.o ./lib/SLB.o ./lib/YLB.o ./lib/LocationArrow.o ./lib/Tabbar.o ./src/main.cpp

compile:
	
	g++ -I ./include/list/ -o ./lib/SatirListesiNode.o -c ./src/components/lists/SatirListesiNode.cpp
	g++ -I ./include/list/ -o ./lib/YoneticiListesiNode.o -c ./src/components/lists/YoneticiListesiNode.cpp
	g++ -I ./include/list/ -o ./lib/SatirListesi.o -c ./src/components/lists/SatirListesi.cpp
	g++ -I ./include/list/ -o ./lib/YoneticiListesi.o -c ./src/components/lists/YoneticiListesi.cpp

	g++ -I ./include/other/ -o ./lib/Actions.o -c ./src/components/other/Actions.cpp
	g++ -I ./include/other/ -o ./lib/Content.o -c ./src/components/other/Content.cpp
	g++ -I ./include/other/ -o ./lib/Converter.o -c ./src/components/other/Converter.cpp
	g++ -I ./include/other/ -o ./lib/StringMethod.o -c ./src/components/other/StringMethod.cpp

	g++ -I ./include/ui/ListBuilders/ -o ./lib/SLB.o -c ./src/ui/ListBuilders/SLB.cpp
	g++ -I ./include/ui/ListBuilders/ -o ./lib/YLB.o -c ./src/ui/ListBuilders/YLB.cpp
	g++ -I ./include/ui/locationArrow/ -o ./lib/LocationArrow.o -c ./src/ui/locationArrow/LocationArrow.cpp
	g++ -I ./include/ui/tabBar/ -o ./lib/Tabbar.o -c ./src/ui/tabbar/Tabbar.cpp

	g++ -c ./src/main.cpp -o ./lib/main.o 

	g++ ./lib/Actions.o ./lib/Content.o ./lib/Converter.o ./lib/LocationArrow.o ./lib/SatirListesi.o ./lib/SatirListesiNode.o ./lib/SLB.o ./lib/StringMethod.o ./lib/Tabbar.o ./lib/YLB.o ./lib/YoneticiListesi.o ./lib/YoneticiListesiNode.o ./lib/main.o -o ./bin/program

run:
	./bin/program