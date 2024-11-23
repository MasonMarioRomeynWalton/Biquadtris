CXX =  g++-14 -std=c++20 -fmodules-ts
CXXFLAGS = -Wall -g
HEADERFLAGS = -c -x c++-system-header
SOURCES = level.cc level-impl.cc concrete_levels.cc level0.cc level1.cc level2.cc level3.cc player.cc player-impl.cc observer.cc subject.cc subject-impl.cc game.cc game-impl.cc text.cc text-impl.cc main.cc
HEADERS = sstream fstream iostream cstdlib string vector 
EXEC = a.out

$(EXEC): $(SOURCES)
	rm -rf gcm.cache
	$(CXX) $(HEADERFLAGS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEC)

.PHONY: clean 
clean:
	rm -f $(EXEC)

