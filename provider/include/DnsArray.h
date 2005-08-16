 /**
 * DnsArray.h
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
#ifndef DNSARRAY_H
#define DNSARRAY_H

#include <string>
#include <vector>
#include <iterator>

using namespace std;

typedef list<string> DnsArrayContainer;
typedef list<string>::iterator DnsArrayIterator;
typedef list<string>::const_iterator DnsArrayConstIterator;

class DnsArray: list<string>  {
    DnsArrayContainer dns_array;

    private:
	void removeChars(string &str, const char *c);
        void splitArrayStr(string);

    public:
	DnsArray(const char *);
	DnsArray();
	~DnsArray();

	bool populate(const char *);

	void add(string);
	void remove(string);
	int size();

	bool isPresent(string);
	string toString();
	const char **DnsArray::toArray();

	DnsArrayConstIterator begin();
	DnsArrayConstIterator end();	
};
#endif
