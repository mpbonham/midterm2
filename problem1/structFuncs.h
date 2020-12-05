#ifndef STRUCTFUNCS_H
#define STRUCTFUNCS_H

template<typename S>
unsigned long getPadding(S s) {

	unsigned long size = sizeof(s); // size of the struct s
	
	unsigned long extra = sizeof(s.cardNumber);
	extra += sizeof(s.firstNameInitial);
	extra += sizeof(s.expirationDate);
	extra += sizeof(s.lastNameInitial);
	extra += sizeof(s.linkedCheckingAccountNumber);
	extra += sizeof(s.bankNameInitial);
	extra += sizeof(s.isActive);
	extra += sizeof(s.cvv);
	
	//extra is the size of all of the struct variables
	unsigned long padding = size - extra;
	return padding;
}

#endif
