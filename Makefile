all:
	gcc detector.c -o detector -lm

debug:
	gcc detector.c -o detector.debug -g3 -lm

clean:
	rm -f detector

.PHONY: all clean