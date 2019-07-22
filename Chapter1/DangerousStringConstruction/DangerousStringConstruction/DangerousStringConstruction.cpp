// Copyright © 2019 by Xitalogy.  MIT license:  https://opensource.org/licenses/MIT

#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>

std::string numToHexStr(uintptr_t num, size_t size)
{
  std::stringstream ss;

  uintptr_t mask{ 0 };
  size_t shiftBits = (sizeof(mask) - size) * 8;

  mask = (~mask << shiftBits) >> shiftBits;

  ss << std::hex << std::uppercase << std::setw(static_cast<std::streamsize>(size) * 2) << std::setfill('0') << (num & mask);

  return ss.str();
}

struct sMeta {
  std::string desc;
  std::string val;
};

struct dMeta {
  std::string desc;
  size_t len;
};

std::string printStrs(const std::vector<sMeta>& strMeta) {
  std::stringstream ss;

  for (size_t ii = 0; ii < strMeta.size(); ii++) {
    ss << strMeta[ii].desc << ": |" << strMeta[ii].val << "|" << std::endl;
  }
  return ss.str();
}

std::string printDmp(const char* stp, const std::vector<dMeta>& dmpMeta)
{
  std::stringstream ss;

  ss << "Hex Dump of Structure Memory - Low Address ----> High Address" << std::endl << " ";

  for (size_t ii = 0; ii < dmpMeta.size(); ii++) {
    ss << std::setw(static_cast<std::streamsize>(dmpMeta[ii].len) * 2 + 1) << std::left << dmpMeta[ii].desc;
  }

  ss << std::endl << "|";

  size_t ii{ 0 };
  size_t kk{ 0 };
  size_t sz = sizeof(stp[0]);

  while (true) {
    for (size_t jj = 0; jj < dmpMeta[ii].len; ++jj, ++kk) {
      ss << numToHexStr(stp[kk], sz);
    }
    if (++ii < dmpMeta.size()) {
      ss << ' ';
    }
    else {
      break;
    }
  }

  ss << "|";

  return ss.str();
}

void printAll(const char* stp, const std::vector<sMeta>& strMeta, const std::vector<dMeta> dmpMeta) {
  std::cout << printStrs(strMeta) << printDmp(stp, dmpMeta) << std::endl << std::endl;
}

int main()
{
  const struct {
    
    char cs[8]{ "1234567" };
    char* csp{ &cs[2] };

    std::vector<sMeta> strMeta{ { "st01 &st", "0x" + numToHexStr(reinterpret_cast<uintptr_t>(cs), sizeof(&cs[0])) },
                                { "st01 s1.", std::string{ cs } },
                                { "st01 cs.", "0x" + numToHexStr(reinterpret_cast<uintptr_t>(cs), sizeof(&cs[0])) },
                                { "st01 s2.", std::string{ csp } },
                                { "st01 csp", "0x" + numToHexStr(reinterpret_cast<uintptr_t>(csp), sizeof(csp)) },
                                { "st01 s3.", std::string { "1234567" } } };

    std::vector<dMeta> dmpMeta{ { "cs", sizeof(cs) }, {"csp", sizeof(csp) } };
  } st01;

  printAll(reinterpret_cast<const char*>(&st01), st01.strMeta, st01.dmpMeta);

  const struct {
    char a1[8]{ '1', '2', '3', '4', '5', '6', '7', '\0' };
    char* a1p{ a1 };

    std::vector<sMeta> strMeta{ { "st02 &st....", "0x" + numToHexStr(reinterpret_cast<uintptr_t>(a1), sizeof(&a1[0])) },
                                { "st02 s1.....", std::string{ a1 } },
                                { "st02 a1.....", "0x" + numToHexStr(reinterpret_cast<uintptr_t>(a1), sizeof(uintptr_t)) },
                                { "st02 s2.....", std::string{ a1p + 4 } },
                                { "st02 a1p....", "0x" + numToHexStr(reinterpret_cast<uintptr_t>(a1p), sizeof(a1p)) },
                                { "st02 a1p + 4", "0x" + numToHexStr(reinterpret_cast<uintptr_t>(a1p + 4), sizeof(a1p + 4)) } };

    std::vector<dMeta> dmpMeta{ { "a1", sizeof(a1) }, { "a1p", sizeof(a1p) } };
  } st02;

  printAll(reinterpret_cast<const char*>(&st02), st02.strMeta, st02.dmpMeta);

  const struct {
    char a1[4]{ '1', '2', '3', '4' };
    char a2[4]{ '5', '6', '7', '\0' };

    std::vector<sMeta> strMeta{ { "st04 s1", std::string { a1 } }, { "st04 s2", std::string { a2 } } };

    std::vector<dMeta> dmpMeta{ { "a1", sizeof(a1) }, { "a2", sizeof(a2) } };
  } st04;

  printAll(reinterpret_cast<const char*>(&st04), st04.strMeta, st04.dmpMeta);

  const struct {
    char a1[4]{ '1', '2', '3', '4' };
    char a2[1]{ '\0' };
    char a3[4]{ '5', '6', '7', '\0' };

    std::vector<sMeta> strMeta{ { "st05 s1", std::string { a1 } }, { "st05 s2", std::string { a2 } }, { "st05 s3", std::string { a3 } } };

    std::vector<dMeta> dmpMeta{ { "a1", sizeof(a1) }, { "a2", sizeof(a2) }, { "a3", sizeof(a3) } };
  } st05;

  printAll(reinterpret_cast<const char*>(&st05), st05.strMeta, st05.dmpMeta);

  const struct {
    char a1[4]{ '1', '2', '3', '4' };
    int  i{ 0 };
    char a2[4]{ '5', '6', '7', '\0' };

    std::vector<sMeta> strMeta{ { "st06 s1", std::string { a1 } }, { "st06 i.", "0" }, { "st06 s2", std::string { a2 } } };

    std::vector<dMeta> dmpMeta{ { "a1", sizeof(a1) }, { "i", sizeof(i) }, { "a2", sizeof(a2) } };
  } st06;

  printAll(reinterpret_cast<const char*>(&st06), st06.strMeta, st06.dmpMeta);

//  const struct {
//    char* np{ nullptr };
    // Exception thrown at 0x0F42F6E0 (ucrtbased.dll) in DangerousStringConstruction.exe: 0xC0000005: Access violation reading location 0x00000000. occurred
//    std::vector<sMeta> strMeta{ { "st04 np", std::string { np } } };
//  } st07;
}