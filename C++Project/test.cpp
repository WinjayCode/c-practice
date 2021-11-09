// my first cpp file

// 预编译指令include,C++当中的预编译指令有好几种，除了include之外还有define、ifdef、undef等等。对于库函数我们需要首先查找到它对应的头文件，将其include之后再进行使用。
/*
* include这个指令会引入一个源代码文件，后面跟着的是一个包含文件名，也叫头文件名。
* C语言中的头文件以.h结尾，而C++当中兼容了C语言的头文件，只不过将其重新命名，去掉了末尾的.h，而换成了c开头。比如math.h文件替换成了cmath。
* iostream为C++的标准输入输出库，用来在终端读入或者打印文本信息。iostream可以拆开理解成io和stream，其中io表示input、output即输入输出，stream表示流，即使用流形式进行io。
*/
#include <iostream>

// 数学计算相关库，例如计算平方根的函数sqrt
#include <cmath>


// 命名空间是C++当中的特性，用来解决大型项目名称冲突的问题。
/*
* 有可能多个程序员同时开发了getValue函数，但当我们编译运行的时候，编译器无法知道我们究竟调用的是哪一个getValue，所以需要使用命名空间进行区分。
* 比如A程序员将getValue放入了名为A的命名空间当中，那么当我们调用getValue的时候就需要写成A::getValue，B程序员将它放入了名为B的命名空间中，同样调用的时候写成B::getValue。
* 然而常用的许多函数、变量都命名在std的命名空间当中，这就意味着当我们使用这类内容的时候，都需要在前面加上std::，比如标准输出的cout命令，需要写成std::cout。
* 这会导致编码变得繁琐，所以C++提供了using namespace的功能，即告诉编译器当前使用的命名空间名称，这样我们在调用该命名空间的内容时，可以省略前缀。
* 除了using namespace之外我们也可以单独使用using命令，例如：
* using std::cout;
* using std::cin;
*/
using std::cout;
using std::cin;
using namespace std;


// 函数命名
/*
* 函数命名同样遵循大驼峰命名法，即首字母以及每个单词首字母大写。
* 对于特殊的缩写单词，通常将它们视作是普通单词，而不会全部大写，如：
* void GetUrl(); // 正确
* void GetURL(); // 错误
*/


// 自定义函数
/*
* C++当中函数同样分为声明和实现，函数的声明一定要写在main函数之前，否则main函数在调用的时候将会找不到对应的函数，报错error: use of undeclared identifier。
* 所以一种正确的写法是在main函数之前写上函数的声明，函数的实现写在main函数之后。其实只需要保证函数声明在main函数之前即可，函数的实现并不限制摆放位置。
* 对于函数的声明，和变量的声明类似，它分为三个部分。分别是函数返回类型，函数名和函数所需的外界参数。
* 如果函数无需外界参数，也需要保留小括号。
* 另外在函数的声明当中，变量名也可以省略，只需要标注类型即可。
*/
void test();

int getResult(int, int);

int getValue(int x, int y);

int getValue(int x, int y) {
	return x + y;
}


void cout_p();
// 标准输出工具，可以将字符串输出在终端中。
/*
* cout本身是一个预定义的对象，它知道如何显示字符串、数字和单个字符。<<符号表示将字符串发送给cout，由cout输出在屏幕当中。<<符号表示了信息流动的路径，<<符号可以多个叠加连接，比如：
* cout << "hello" << "world"；
*/
// endl表示当前输出行的结束，cout遇到endl时会重启一行，否则则会接在同一行后面继续输出。
/*
* 除了使用endl之外，我们也可以使用换行符来达到同样的效果，如：
* cout << "hello" << "world\n";
*/
/*
* C++ Primer当中建议在输出由内容的字符串时使用换行符，而非endl，其他情况下使用endl，而非换行符。这两者绝大多数情况下是等价的，在一些特殊情况下可能会构成差异。
* 如endl确保程序继续运行前刷新输出，而使用"\n"则意味着有时候需要在输入信息之后才会出现提示。
*/
void cout_p() {
	// cout输出结果时可以通过多个<<符号进行拼接
	cout << "hello " << "c++" << endl;
}



void cin_p();
// cin顾名思义，表示读入，它可以从屏幕（终端）读入数据，流向我们指定的变量。
/*
* cin是输入数据的对象，数据从cin流向了wordCnt。即我们在终端输入的数据被读入到了wordCnt当中。
* 和cout一样，我们可以从终端读入多种类型的数据，如浮点数、整数、字符串等，cin会自动将读入的数据转化成对应的数据类型并完成赋值。
*/
void cin_p() {
	int wordCnt;
	int personCnt;
	int roomCnt;
	wordCnt = personCnt = roomCnt = 2;

	cout << "wordCnt=";
	cin >> wordCnt;

	cout << "word count: " << wordCnt << ", room count: " << roomCnt << endl;
}


void sqrt_p();
// 计算平方根
void sqrt_p() {
	double a = sqrt(9.0);
	cout << "a=" << a << endl;
}


void method_p();
// 函数
void method_p() {
	cout << "4+5=" << getValue(4, 5) << endl;
}


void sizeof_p();
// 当我们查看对象是变量类型时，需要使用括号，如果是变量本身，则括号是可选的。
void sizeof_p() {
	cout << "sizeof(int)=" << sizeof(int) << endl;
	int a = 6;
	cout << "sizeof int=" << sizeof a << endl;
}


void longlong__int64_p();
// long long 和 __int64
void longlong__int64_p() {
	long long a;
	scanf_s("%lld", &a);
	printf("long long = %lld\n", a);

	__int64 b;
	scanf_s("%I64d", &b);
	printf("__int64 = %I64d\n", b);
}


void char_p();
// char
void char_p() {
	char a = 'a';
	cout << "++a = " << ++a << endl;

	char b = 'b';
	cout << "--b = " << --b << endl;

	char c = '1';
	int num = c - '0';
	cout << "'1' - '0' = " << num << endl;

	char d = '1';
	if (d >= '0' && d <= '9') {
		cout << "1 is a number" << endl;
	}

	char e;
	cin.get(e);
	cout.put(e);

	//string str = "ten.gnehcnaib.c//:ptth";
	//for (int i = str.length() - 1; i >= 0; i--) {
	//	cout.put(str[i]);  //从最后一个字符开始输出
	//}
	//cout.put('\n');
}


void float_p();
// 浮点数类型
void float_p() {
	double a = 2.45e8; // 2.45*10^8
	double b = 1e-7; // 10^-7

	double epsilon = 1e-8;
	// 判断a和b是否相等
	if (abs(a - b) < epsilon) {
		cout << "a == b" << endl;
	} else {
		cout << "a != b" << endl;
	}

	float c = 2.3e22f;
	float d = c + 1.0f;

	cout << d - c << endl;
}


void calculate_p();
// 算术运算符
void calculate_p() {
	int a = 10, b = 3;

	cout << "10 + 3=" << a + b << endl;
	cout << "10 - 3=" << a - b << endl;
	cout << "10 * 3=" << a * b << endl;
	cout << "10 / 3=" << a / b << endl;
	cout << "10 % 3=" << a % b << endl;

	long long c = 0x3f3f3f3f3f3f3f;
	int d = a;
	cout << "long long:0x3f3f3f3f3f3f3f -> int=" << d << endl;

	// 允许低精度转高精度
	int e = 0x3f3f3f3f;
	long f = {e};
	cout << "int:0x3f3f3f3f -> long=" << f << endl;

	// 不允许高精度转低精度
	//long g = 2147483647999999999;
	//int h = {g};
	cout << "long:2147483647999999999 -> int=" << "Not Allowed" << endl;

	const int i = 55;
	char j = { i };
	cout << "const int 55 -> char=" << j << endl;

	//int k = 55;
	//char l = { k };
	cout << "int 55 -> char=" << "Not Allowed"<< endl;

	int m = 11.99 + 19.99;
	cout << "11.99 + 19.99=" << m << endl;

	int n = (int)11.99 + (int)19.99;
	cout << "(int)11.99 + (int)19.99=" << n << endl;
}

// main函数是C++程序的入口函数，C++标准当中定义的main函数类型是int。返回0表示程序正常退出，所以一般我们要在main函数的最后写上return 0。
/*
* C++的main函数通常有两种写法，一种是参数留空，一种是定义参数数量以及参数值。
* int main() {}
* int main(int argc, char* argv[]) {}
*/
int main() {
	int index = 0;
	cout << ++index << ".cout" << endl;
	cout << ++index << ".cin" << endl;
	cout << ++index << ".sqrt" << endl;
	cout << ++index << ".fuction" << endl;
	cout << ++index << ".sizeof" << endl;
	cout << ++index << ".long long/__int64" << endl;
	cout << ++index << ".char" << endl;
	cout << ++index << ".float" << endl;
	cout << ++index << ".calculate" << endl;
	cout << endl;

	cout << "num=" << endl << endl;
	int num;
	cin >> num;
	cout << endl;


	if (num == 1) {
		cout_p();
	}

	if (num == 2) {
		cin_p();
	}
	
	if (num == 3) {
		sqrt_p();
	}

	if (num == 4) {
		method_p();
	}
	
	if (num == 5) {
		sizeof_p();
	}
	
	if (num == 6) {
		longlong__int64_p();
	}
	
	if (num == 7) {
		char_p();
	}

	if (num == 8) {
		float_p();
	}

	if (num == 9) {
		calculate_p();
	}

	return 0;
}

// 变量规范
/*
* C++当中变量的声明由变量类型 + 变量名组成。
* 关于C++的命名有几种规则：
*	名称中只能使用字母、数字和下划线
*	名称的第一个字符不能是数字
*	大小写敏感
*	不能使用C++关键字（如class、void等）
*	用户自定义的标识符中不能连续出现两个下划线，也不能以下划线紧跟大写字母开头，此外定义在函数体外的标识符不能以下划线开头
*	C++对于名称长度没有限制，但部分平台有限制
* 总则:
*	总的原则是尽可能使用描述性的命名，不吝啬变量长度，因为相比之下让代码容易理解比容易敲出来更重要。
*/


// 类型命名
/*
* 类型命名采用大驼峰命名，不包含下划线，如：MyExcitingClass，HelloWorldClass等。
* 所谓类型命名包括类，结构体，类型定义（typedef），枚举，类型模板参数，它们均使用相同的约定。即大写字母开头，每个单词的开头也为大写，即大驼峰。
* 类和结构体：
* class UrlTable { ...
* class UrlTableTester { ...
* struct UrlTableProperties { ...
*
* 类型定义：
* typedef hash_map<UrlTableProperties *, string> PropertiesMap;
*
* using 别名
* using PropertiesMap = hash_map<UrlTableProperties *, string>;
*
* 枚举
* enum UrlTableErrors { ...
*/


// 变量命名
/*
* C++的变量没有像Java一样遵循小驼峰，而是一律小写，单词和单词之间以下划线连接。
* string table_name;  // 好 - 用下划线.
* string tablename;   // 好 - 全小写.
* string tableName;  // 差 - 混合大小写
*
* 但如果是类中的数据成员（成员变量），则变量的末尾需要额外的下划线：
* class TableInfo {
*	 ...
*	private:
*	 string table_name_;  // 好 - 后加下划线.
*	 string tablename_;   // 好.
*	 static Pool<TableInfo>* pool_;  // 好.
* };
*
* 但结构体除外，仍然和普通变量一样命名。
* struct UrlTableProperties {
*	string name;
*	int num_entries;
*	static Pool<UrlTableProperties>* pool;
* };
*/


// 常量命名
/*
* 声明为constexpr和const的变量，或者是其他没有显示定义但是在程序运行当中保持不变的，命名是以k开头，并且大小写混合，如：
* const int kDaysInAWeek = 7;
*/


// 声明变量
/*
* 在C++当中所有的变量都需要声明
* 我们声明了一个int类型的变量wordCnt，这样的语句会告诉编译器两个关键信息。一个是变量所需要的内存，一个是这块内存的名称。
* 比如在这个例子当中，我们声明了一个int型的变量。它占据32个二进制位，也就是4个字节，这块内存的名称被叫做wordCnt。
*	 int wordCnt;
*/


// 赋值语句
/*
* 变量被声明了之后，我们就可以通过赋值语句给它赋上我们想要的值。
*	wordCnt = 1;
*/


// 连续赋值的写法
/*
* int personCnt;
* int roomCnt;
* wordCnt = personCnt = roomCnt = 2;
*/


// 文件命名
/*
* 文件名全部要小写，可以包含下划线以及字符-，最好使用下划线。
*/


// 命名空间
/*
* 全部小写命名
*/


// 宏命名
/*
* 宏命名为全部大写，并且以下划线分割，如：
* #define ROUND(x) ..
* 不过不推荐在代码中使用宏。
*/


// 枚举命名
/*
* 与常量或宏一致，即kEnumName或ENUM_NAME。个人更倾向于后者。
*/


// 整形
/*
* 整型即整数，与小数对应。
* C++的基本整型有char、short、int、long，在C++ 11标准中，新增了long long。在部分编译器当中不支持long long，而支持__int64。
* 每一种类型都有有符号版本和无符号版本两种，所以总共一共有10种类型。
*/


// short、int、long和long long
/*
* 这四种类型都是整型，唯一的不同是范围的区别。受到底层硬件的影响，C++当中这四种类型的范围并不是固定的。由于要兼容各种不同类型的系统与硬件，所以没有办法对类型进行统一。
* 为了避免引起不便，C++提供了一种灵活的标准，它确保了每一种类型的最小范围。
*	short至少16位
*	int至少与short一样长
*	long至少32位，且至少与int一样长
*	long long至少64位，且至少与long一样长
*/


// 位与字节
/*
* 计算机内存的基本单元是位，英文是bit，音译成比特。一位bit只有0和1两个值，可以将其看成是开关。8位bit一共有256中不同的组合，即2^8=256。因此8位bit可以表示0-255或者-128-127。
* 每增加一个二进制位，可以表示的范围翻倍。因此16位可以表示65536个值，而32位可以表示4294672296个值，64位更大，大约能表示1.8*10^19。这个范围足够表示银河系中所有的星星。
* 8位二进制位是一个字节（byte），字节是计算机存储的最小计量单位。1024个字节称为1KB，而1024个KB又被称为1MB，1024MB为1GB。
* 一般在操作系统当中，都有最小长度，这通常是由CPU的位数所决定的。在常用的操作系统当中如Linux、Windows、MacOS，int和long为32位，short为16位，而long long为64位。
* 除了根据通常情况来推测之外，C++当中也提供了一些现成的工具来查看。比如sizeof函数，sizeof函数可以查看变量占据的字节数。
*	(这个函数既可以接受变量类型也可以接受变量本身，如果传入的是变量类型，那么计算的结果就是该类型的变量占据的内存大小，同理如果是变量本身，则表示变量本身占据的内存。)
* 除了sizeof函数之外，C++还提供了大量的常量。比如INT_MAX，LONG_MAX等，顾名思义这些常量的值就是各个类型的最大值。最小值，如INT_MIN，LONG_MIN等
*/


// 无符号类型
/*
* 比如8位二进制位既可以表示0-255也可以表示-128-127。这其实就是有符号和无符号的区别。
* 如果我们确定我们要存储的整数为非负数，并且想要拥有更大的范围，就可以使用无符号修饰符unsigned来修饰这几种类型。比如：
*	unsigned short ushort;
*	unsigned int uint;
*	unsigned long ulong;
*	unsigned long long ull;
*/


// long long 和 __int64
/*
* 在C++ Primer当中提到的64位的int只有long long，但是在实际各种各样的C++编译器当中，64位的int一直有两种标准。一种是long long，还有一种是__int64，非主流的VC甚至还支持_int64。
*/


// cin、cout和scanf、printf的选择问题
/*
* 这个问题对于C++开发工程师来说同样不是个问题，没有任何选择的必要，无脑用cin、cout就完事了。但对于算法竞赛玩家来说，这依然是一个要考虑的问题。
* 因为在算法竞赛当中，尤其是当数据量很大的时候，读入和输出占据的时间是非常可观的。看起来只是cin cout和scanf和printf的差别，但是两者的性能差异非常大。
* 关于性能差异的原因，主要有两种解释。一种解释是说cin为了与scanf混用，而不用担心指针混乱，加上了绑定，总是会与stdin保持同步。正是这一步操作消耗了大量的时间。同理，cout也会有类似的问题。
* 第二种解释是cout在输出之前会把要输出的内容先存入缓存区，中间多了一个步骤，也会带来性能的降低。
* 关于cin与stdin同步带来的开销，我们是有办法解决的，只需要在加上这一行代码：
*	std::ios::sync_with_stdio(false);
* 这行代码的意思是取消cin、cout与stdin、stdout的指针同步，会使得cin、cout的性能大大提升，达到和scanf、printf相差无几的程度。当然，更好的方法是使用scanf、printf代替。
*
* 而要使用scanf和printf又有一个问题，它们是C语言的标准输入输出方式，需要提供标识符来代表变量的类型，
* long long的标识符是lld，所以我们使用scanf读入一个long long类型的数写成：
*	long long a;
*	scanf("%lld", &a);
*
* __int64的标识符是I64d，注意这里是大写的i，不是l
*	__int64 a;
*	scanf("%I64d", &a);
*
*
* 变量定义	输出方式	gcc(mingw32)	g++(mingw32)	gcc(linux i386)	g++(linux i386)	MicrosoftVisual C++ 6.0
* long long	“%lld”	  错误				错误			正确			正确			无法编译
* long long	“%I64d”	  正确				正确			错误			错误			无法编译
* __int64	“lld”	      错误				错误			无法编译		无法编译		错误
* __int64	“%I64d”	  正确				正确			无法编译		无法编译		正确
* long long	 cout	      非C++				正确			非C++			正确			无法编译
* __int64	 cout	      非C++				正确			非C++			无法编译		无法编译
* long long	printint64()  正确				正确			正确			正确			无法编译
*/


// char类型
/*
* char的全称是character，也就是字符的意思。顾名思义，char类型是专门为了存储字符而设计的。
* 计算机存储数字非常方便，只需要将其转化成二进制即可。但存储字符就有点麻烦了，一般都是通过对字符进行数字化编码。这也就是为什么char类型本质上是另外一种整数，因为它存储的其实是字符的数字编码。
* char一共有8个二进制位，即一个字节，理论上能够存储256个字符。基本上足够涵盖计算机当中所有的字母、标点符号以及数字，即ASCII码。
* ASCII的全称是美国信息交换标准代码，它是一套电脑编码系统，包含了所有英文字母以及标点符号和一些特殊字符。全表一共有128个字符，刚好可以用一个char（有符号）来存储。
* 当我们把一个字符赋值给char型变量的时候，它会去查ASCII表，找到字符对应的编号。同样，当我们使用%c输出一个字符的时候，它也会去寻找char中存储的编码对应的符号进行输出。
* 既然字符在C++当中都是以数字的形式存储的，那么我们就可以对它来进行加减运算。比如：
*	char c = 'a';
*	cout << ++c << endl;
* 
* 得到的结果是'b'，有加自然也有减，我们也可以对它做减法操作。
*	char c = 'b';
*	cout << --b << endl;
* 
* 另外，我们还可以对于两个char类型的变量进行减法操作。比如用得比较多的就是将字符型的数字转成int型。
*	char c = '1';
*	int num = c - '0';
* 
* 我们还可以通过大于小于符号来判断char类型的范围：
*	char c = '1';
*	if (c >= '0' && c <= '9') {
*		cout << "c is a number" << endl;
*	}
*/


// getchar、putchar、cin.get、cout.put
/*
* getchar和putchar都是C语言当中专门面向字符IO的函数，也就是读入和输出字符的函数。
* 因为确定了处理的数据类型是字符，不需要额外的格式说明，因此getchar和putchar的效率要比scanf和printf更高。
* 所以在算法竞赛领域，有人为了提升程序的性能，丧心病狂地使用getchar代替scanf来读入数据。
* 我这里贴一段使用getchar来读入int型的代码，给大家做一个参考。这个属于标准的奇淫技巧，不推荐使用。
*	void read(int &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') {
        if (s == '-') {
            f = -1;
            s = getchar();
        }
    }
    while (s >= '0' && s <= '9') {
        x = x * 10 + s - '0';
        s = getchar();
    }
    x *= f;
	}
* 
* cin.get和cout.put与getchar和putchar的用法类似，只不过是C++当中的特性。大家可以参考一下下面这个例子，就不过多赘述了。
*	char c;
*	cin.get(c);
	cout.put(c);
*/


// 浮点数的使用
/*
* C++当中有两种浮点数的书写方式，第一种是使用常规的小数点表示法：
*	double a = 1.23;
*	float b = 3.43;
* 另外一种写法是科学记数法，写成：
*	double a = 2.45e8;
*	double b = 1e-7;
*/


// 浮点数类型
/*
* 和C语言一样，C++也有三种浮点数类型：float,double和long double。和整型一样，这三种类型都是浮点数，只不过表示的范围不同。
* 浮点数的范围有两个部分综合决定，一个部分是有效数字。比如14179是5位有效数字，而14000只有两位，因为后面三个0都是填充位，有效数字的位数不依赖小数点的位置。
* C++当中要求，float通常表示7位有效数字，double通常16位位，而long double至少和double一样。
* 另外，它们能够表达的指数范围至少是-37到37。一般来说，float一共是4个字节32位，而double是8个字节64位，当然这也取决于具体的运行环境。
* 
* 注意事项
* 关于浮点数的使用有几点注意事项，千万要注意。
*	1.cout输出浮点数会删除结尾的0
*	2.书写浮点数常量时默认为double类型，如果需要强制表示为float类型，请在结尾加上后缀f或者F，如：2.34f
*	3.由于浮点数有精度，不能直接判断两个浮点数是否相等，很有可能得不到预期结果，正确的做法是判断精度范围，如：
*		double epsilon = 1e-8;
*		// 判断a是否和b相等
*		if (abs(a - b) < epsilon) {
*			// todo
*		}
* 判断两个浮点数a和b是否相等，等价于两者的差的绝对值小于某一个精度。
*	4.范围问题，如运行下列代码将得到错误的结果：
*		float a = 2.3e22f;
*		float b = a + 1.0f;
*		cout << b - a << endl;
* 输出的结果将是0，因为2.3e22是一个小数点左边有23位的数字，加上1之后，就是在第23位加上1。但是float类型只能表示数字中的前6位或者前7位，表示不了这么高的精度，因此这个+1的操作完全没有生效。
* 这个问题是一个大坑，一不小心就会中招，千万要小心。
*/


// 算术运算符
/*
* C++当中提供5种基础的算术运算符：加法、减法、乘法、除法和取模。
* 前面三个都非常简单，着重讲下最后两种。
* 对于除法来说，我们要注意的是它是区分类型的。当我们的除数和被除数都是整数的时候，得到的结果也会是一个整数。
* 所以10 / 3得到的结果就是3，它的小数部分会被抛弃。想要得到小数结果，只需要除数或者被除数当中有一个是浮点型即可。
* 取模运算符求的就是一个数除以另外一个数之后的余数。这里要注意，在其他语言当中并没有对取模运算的限制，而在C++当中，严格限制了取模运算的对象只能是整数。否则编译的时候会报错。
* 
* 优先级
* C++当中算术运算符的优先级和我们从小数学课本里是一样的，先乘除再加减。
* 即当乘除法和加减法同时出现时，先算乘除后算加减。如果有多个运算符同样优先级，那么先左后右。
* 
* 类型转换
* 1.初始化和赋值时的转换
* 当我们对某个值进行初始化或者赋值的时候，C++会自动将赋予的值转化成接收者的类型。比如：
*	float a = 3.5f;
*	double b = a;
* 在上面这个例子当中，我们将一个float类型的变量a赋值给了double类型的b。那么编译器会将a的值拓展成64位的double再赋值给b。也就是说不会影响b的类型。
* 这样将长度更短的变量转化成更长变量的类型转换除了多占用一点内存之外，不会导致什么问题。但反向操作可能就会出错，比如：
*	long long a = 0x3f3f3f3f3f3f3f;
*	int b = a;
* 在上面的例子当中，我们将一个long long赋值给了int，由于a的数值非常大超过了int能够承载的范围，进行这样的赋值之后，编译器并不会报错（甚至不会有警告），但将会导致结果错误。b变量将不可能再和a变量相等。
* 再比如将float变量赋值给int的时候，同样也会有类似的问题，所以在进行赋值的时候，当两个变量的类型不同时，千万要当心。
* 
* 2.使用花括号进行转换
* 这是C++ 11的新特性，使用大括号进行初始化，这种操作被称为列表初始化。
* 这种方式的好处和坏处都很明显，好处是它不允许变量长度缩窄的情况，坏处则是又增加了学习的成本。
* 例如，不允许将浮点型转换成整型。在不同的整型之间以及整型转化成浮点型的操作可能被允许，取决于编译器知道目标变量能够正确地存储赋给它的值。比如可以将int类型赋值给long，因为long总是至少与int一样长，反向操作则会被禁止。
*	int a = 0x3f3f3f3f;
*	long b = {a};   // 允许
*
*	long a = 0x3f3f3f3f;
*	int b = {a};    // 禁止
* 关于列表初始化，C++ primer当中还列举了一个非常有意思的case：
*	const int x = 55;
*	char c = {x};   // 允许
*
*	int x = 55;
*	char c = {x}; // 禁止
*
*	const int x = 1255;
*	char c = {x};   // 禁止
*
*	const int x = 1255;
*	char c = x;  // 允许会警告
* 因为我们加了const修饰之后，编译器就明确知道了x的值，就等于55，它在char类型的范围内，所以允许将它转化成char。如果不加const，那么在编译器看来x是一个int型的变量，它的范围要大于char，所以会禁止。即使我们加了const修饰，如果x的值过大，超过char的范围，也同样会被禁止。
* 
* 3.表达式中转换
* 表达式时C++会将bool、char、unsigned char、signed char和short全部转换为int
* 对于bool类型来说，true会被转化成1，false转换成0，其他类型的转换应该都很好理解，都是将范围更小的变量转化成范围更大的int，这种转换称作整型提升。因为通常int类型都是计算机最自然的类型，也意味着计算机在处理int的时候，处理的速度最快。
* 将不同类型进行运算的时候，也会做一些转换。比如将int和float相加的时候，由于涉及到两种类型，其中范围较小的那个会被转换成较大的类型。比如如果我们计算9.0 / 5，那么编译器会先将5转化成5.0，再进行除法运算，这样得到的结果自然也是一个double。
* C++11的规范中除了一个类型转换的校验表，我们可以参考一下校验表理解一下类型转换的过程。
*	1.如果有一个数类型是long double，则将另外一个数也转成long double
*	2.否则，如果有一个数类型是double，则将另外一个数也转成double
*	3.否则，如果有一个数类型是float，则将另外一个数也转成float
*	4.否则说明所有操作数都是整数，执行整型提升
* 
* 4.强制类型转换
* 强制类型转换的方式有两种写法：
*	int a;
*	(long) a;
*	long (a);
* 这两行代码都是将一个int型的a转换成long型的，上面的是C语言的写法，底下一行是C++的写法
* 还有一点要注意就是转换的顺序，我们来看一个例子：
*	int a = 11.99 + 19.99;
*	cout << a << endl;
*	int b = int(11.99) + int(19.99);
*	cout << b << endl;
* 在这段代码当中a和b输出的结果是不同的，a输出的结果是31，而b是30。
* 这是因为第一行代码是先计算的加法，得到31.98，再通过类型转换将31.98转换成int。对于浮点数向整型的转换，C++会直接抹掉小数部分，所以得到的结果是31。而第二行代码当中，我们是先进行的类型转换，11.99和19.99分别被转换成了11和19，相加得到的结果也就是30了。
*/