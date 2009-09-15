 /**
 * DnsArray.cpp
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Eclipse Public License from
 * http://www.opensource.org/licenses/eclipse-1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
#include <string>
#include <list>
#include <iostream>

using namespace std;

#include "smt_dns_array.h"

	DnsArray::DnsArray(const char *ptr) {
		splitArrayStr( string(ptr) );
	};

	DnsArray::DnsArray(){};
	
	DnsArray::~DnsArray() {}; 

	bool DnsArray::populate(const char *ptr)
	{
		if ( dns_array.empty() )
		{
			splitArrayStr( string(ptr) );
			return true;
		}
		else 
			return false;
	}


	void DnsArray::removeChars(string &str, const char *c)
        {
                string::size_type pos = 0;
                while (pos != string::npos)
                {
                        pos = str.find(c,pos);
                        if (pos != string::npos)
                                str.erase(pos,1);
                }
        };

        void DnsArray::splitArrayStr(string text)
        {
                removeChars(text," ");
                removeChars(text,"{");
                removeChars(text,"}");

                int n = text.length();
                int start, stop;
                start = text.find_first_not_of(";");

                while ((start >= 0) && (start < n)) {
                        stop = text.find_first_of(";", start);
                        if ((stop < 0) || (stop > n)) stop = n;
                        dns_array.push_back(text.substr(start, stop - start));
                        start = text.find_first_not_of(";", stop+1);
                }
        };

	void DnsArray::add(string s)
	{
		dns_array.push_back( s );
	}

        void DnsArray::remove(string s)
        {
                dns_array.remove( s );
        }


	bool DnsArray::isPresent(string str)
	{
		DnsArrayIterator iter;
		iter = find( dns_array.begin(), dns_array.end(), str);
		
		if ( iter != dns_array.end() )
			return true;
		else
			return false;
	} 

        string DnsArray::toString()
        {
                DnsArrayIterator iter;
                string ret = "{ ";
                
		for ( iter = dns_array.begin(); iter != dns_array.end(); ++iter )
                {
                        ret.append( (*iter).c_str() );
                        ret.append("; ");
                }
                ret.append("}");
                return ret;
        };

	const char **DnsArray::toArray()
        {
                DnsArrayIterator iter;
		char **ret = (char **) malloc( dns_array.size()*sizeof(char *) ); 
		char **arr = ret;

                for ( iter = dns_array.begin(); iter != dns_array.end(); ++iter )
                {
                        *arr = strdup( (*iter).c_str() ) ;
                        arr++;
                }
                return (const char**) ret;
        };

	DnsArrayConstIterator DnsArray::begin()
	{
		//DnsArrayConstIterator iter = dns_array.begin();
		
		return dns_array.begin();
	}

	DnsArrayConstIterator DnsArray::end()
	{
		return dns_array.end();
	}

	int DnsArray::size()
	{
		return dns_array.size();
	}
