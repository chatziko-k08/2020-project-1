# Makefile για τις βιβλιοθήκες k08.a και libbmp.a

# Βρίσκουμε ποιο λειτουργικό σύστημα χρησιμοποιείται
ifeq ($(OS),Windows_NT)
	SUFFIX = win
	COPY = copy
else ifeq ($(shell uname -s),Linux)
	SUFFIX = linux
	COPY = cp
else
	SUFFIX = macos
	COPY = cp
endif

all: k08.a libbmp.a

# "Παράγουμε" το k08.a απλά αντιγράφοντας το αρχείο που αντιστοιχεί στο λειτουργικό σύστημα που χρησιμοποιούμε
k08.a:
	$(COPY) k08_$(SUFFIX).a k08.a

# Το ίδιο για το libbmp.a
libbmp.a:
	$(COPY) libbmp_$(SUFFIX).a libbmp.a

clean:
	$(RM) k08.a libbmp.a