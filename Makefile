VER = g++-14.2.0
CXX = -std=c++20 -fmodules-ts
CXXFLAGS = -Wall -g
HEADERFLAGS = -c -x c++-system-header
SOURCES = blocks.cc blocks-impl.cc newblock.cc newblock-impl.cc centersquare.cc centersquare-impl.cc board.cc board-impl.cc score.cc score-impl.cc level.cc level-impl.cc concrete_levels.cc level0.cc level1.cc level2.cc level3.cc level4.cc player.cc player-impl.cc observer.cc subject.cc subject-impl.cc game.cc game-impl.cc text.cc text-impl.cc main.cc
HEADERS = fstream iostream memory cstdlib string vector utility 
EXEC = a.out

$(EXEC): $(SOURCES)
	rm -rf gcm.cache
	$(VER) $(CXX) $(HEADERFLAGS) $(HEADERS)
	$(VER) $(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEC)

.PHONY: clean 
clean:
	rm -f $(EXEC)

