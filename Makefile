VER = g++-14.2.0
CXX = -std=c++20 -fmodules-ts
CXXFLAGS = -Wall -g
HEADERFLAGS = -c -x c++-system-header
SOURCES = blocks.cc blocks-impl.cc newblock.cc newblock-impl.cc centersquare.cc centersquare-impl.cc board.cc board-impl.cc score.cc score-impl.cc level.cc level-impl.cc concrete_levels.cc level0.cc level1.cc level2.cc level3.cc level4.cc effects.cc player.cc player-impl.cc concrete_effects.cc blind-impl.cc force-impl.cc heavy-impl.cc observer.cc subject.cc subject-impl.cc game.cc game-impl.cc text.cc text-impl.cc window.cc window-impl.cc graphics.cc graphics-impl.cc main.cc
HEADERS = fstream iostream memory cstdlib string vector utility
EXEC = Biquadris

$(EXEC): $(SOURCES)
	rm -rf gcm.cache
	$(VER) $(CXX) $(HEADERFLAGS) $(HEADERS)
	$(VER) $(CXX) $(HEADERFLAGS) unistd.h
	$(VER) $(CXX) $(HEADERFLAGS) X11/Xlib.h
	$(VER) $(CXX) $(HEADERFLAGS) X11/Xutil.h
	$(VER) $(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEC) -lX11

.PHONY: clean 
clean:
	rm -rf gcm.cache
	rm -f $(EXEC)

