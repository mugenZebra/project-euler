#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    char two[] = "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";
    int sum = 0;

    for (int i = 0; i < sizeof(two) - 1; i++){
        cout << two[i];
        sum += (int)(two[i] - 48);
    }

    cout << endl;
    cout << sum << endl;

	// create a couple of arbitrary long integers
	long testA = 34233;
	unsigned long testB = 332311;
	// here we use the bitset template class I'll break it down
	// bitset	: name of the template class as defined in the <bitset header>
	// <32>		: the number of bits we are interested in, a long is garaunteed
	//				to be at least this many bits, we can use less than 32, but
	//				more could potentially be non-portable
	// resultA	: the name of the variable
	// (testA)	: the value we initialize the variable, we could of put the
	//				number itself in or even left it blank which would yield
	//				a bitset of 32 0-bits
	bitset<32> resultA(testA);
	bitset<32> resultB(testB);

	cout << "resultA: " << resultA << endl;
	cout << "resultB: " << resultB << endl;

	// here we output the bitset testA
	cout << "testA (" << testA << "): " << endl;
	for(int i = 0; i < 32; ++i)
	{
		cout << resultA[i];
	}
	cout << endl << endl;
	// output the bitset testB
	cout << "testB (" << testB << "): " << endl;
	for(int j = 0; j < 32; ++j)
	{
		cout << resultB[j];
	}
	cout << endl << endl;

    bitset<4> first (string("1001"));
    bitset<4> second (string("0011"));

    cout << (first^=second) << endl;          // 1010 (XOR,assign)
    cout << (first&=second) << endl;          // 0010 (AND,assign)
    cout << (first|=second) << endl;          // 0011 (OR,assign)

    cout << (first<<=2) << endl;              // 1100 (SHL,assign)
    cout << (first>>=1) << endl;              // 0110 (SHR,assign)

    cout << (~second) << endl;                // 1100 (NOT)
    cout << (second<<1) << endl;              // 0110 (SHL)
    cout << (second>>1) << endl;              // 0001 (SHR)

    cout << (first==second) << endl;          // false (0110==0011)
    cout << (first!=second) << endl;          // true  (0110!=0011)

    cout << (first&second) << endl;           // 0010
    cout << (first|second) << endl;           // 0111
    cout << (first^second) << endl;           // 0101

    cout << "first: "<< first << endl;
    cout << "second: "<< second << endl;
    first = second;
    cout << "first: "<< first << endl;
    first = 1;
    cout << "first: "<< first << endl;
    first = 5;
    cout << "first: "<< first << endl;
    first = 15;
    cout << "first: "<< first << endl;

/*
    bitset<1000> Sieve1;
    bitset<1000> Sieve2;
    int digit[1000];
    sum=0;
    digit[0]=2;
    int count=0;
    do{
        for(int i=1;i<1000;i++) {
            digit[i]=(2*digit[i-1])%10;
            if(Sieve1[i-1]) digit[i]++;
            if(digit[i]>4) Sieve2=1;
        }
        cout<<"\n"<<digit[999];
        sum+=digit[999];
        Sieve1=Sieve2;
        Sieve2.reset();
        digit[0]=0; count++;
    }while(IfZeroArray(digit));

    cout<<"Sum is "<<sum;
    cout<<"\nNo. of digits is "<<count;
*/
    const int num_lights = 15;
    const bitset<num_lights> outside( 0xf );
    const bitset<num_lights> inside( 0xff0 );
    const bitset<num_lights> driveway( 0x7000 );

    cout << "outside: " << outside << endl
         << "inside: " << inside << endl
         << "driveway: " << driveway << endl;

    bitset<10> myBitset;

    myBitset.set(3);
    myBitset.set(6);
    myBitset[8] = true;
    myBitset[9] = myBitset[3];

    if (myBitset.test(3)) {
    cout << "Bit 3 is set!\n";
    }
    cout << myBitset << endl;

    bitset<8> bits = 83;
    cout << bits << "  ";
    cout << bits.to_ulong() << endl << endl;
    bits[0] = 0;
    cout << bits << "  ";
    cout << bits.to_ulong() << endl << endl;
    bits[1] = 0;
    cout << bits << "  ";
    cout << bits.to_ulong() << endl << endl;


	return 0;
}
