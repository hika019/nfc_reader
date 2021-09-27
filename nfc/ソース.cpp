#include "lazypcscfelicalite.h"
#include <iostream>

using LazyPCSCFelicaLite::PCSCFelicaLite;
using LazyPCSCFelicaLite::PCSCErrorException;
using LazyPCSCFelicaLite::PCSCIllegalStateException;
using LazyPCSCFelicaLite::PCSCCommandException;
using LazyPCSCFelicaLite::PCSCFatalException;
using LazyPCSCFelicaLite::PCSCCryptographicException;
using LazyPCSCFelicaLite::FelicaErrorException;
using LazyPCSCFelicaLite::FelicaFatalException;
using LazyPCSCFelicaLite::PCSCCardRemovedException;
using namespace std;

int main() {
	PCSCFelicaLite f = PCSCFelicaLite();

	try {
		cout << "‚©‚´‚µ‚Ä\n";
		f.autoConnectToFelica(INFINITE);

		uint8_t uid[256] = { 0 };
		int len = f.readUID(uid);

		for (int i = 0; i < len; i++) {
			printf("%02X ", uid[i]);
		}
		printf("\n");

	}catch (std::runtime_error e) {
		cout << e.what() << "\n";
	}

	return 0;
}