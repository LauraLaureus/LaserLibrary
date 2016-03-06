# Sensor de distancia URG-04LX

## Instalación

### Linux

Compilar la librería y códigos del ejemplo:

```
$ make
```

## Ejemplo

Código simplificado del ejemplo `lib/urg_library-1.2.0/samples/cpp/get_distance.cpp`
en `src/distance.cpp`:

```cpp
#include "Urg_driver.h"
#include "Connection_information.h"
#include "math_utilities.h"
#include <iostream>

using namespace qrk;
using namespace std;

namespace
{
    void print_data(const Urg_driver& urg,
                    const vector<long>& data, long time_stamp)
    {
        size_t data_n = data.size();

        for (size_t i = 0; i < data_n; ++i) {
            long l = data[i];
            double radian = urg.index2rad(i);
            long x = static_cast<long>(l * cos(radian));
            long y = static_cast<long>(l * sin(radian));

            cout << "(" << x << ", " << y << ")" << endl;
        }

        cout << endl;
    }
}


int main(int argc, char *argv[])
{
    // Conectar al sensor
    Connection_information information(argc, argv);
    Urg_driver urg;

    if (!urg.open(information.device_or_ip_name(),
                  information.baudrate_or_port_number(),
                  information.connection_type())) {
        cout << "Urg_driver::open(): "
             << information.device_or_ip_name() << ": " << urg.what() << endl;

        return 1;
    }

    // Parametro de angulo de escáner desde -90 a 90
    urg.set_scanning_parameter(urg.deg2step(-90), urg.deg2step(+90), 0);

    // Número de capturas
    enum { Capture_times = 10 };
    urg.start_measurement(Urg_driver::Distance, Urg_driver::Infinity_times, 0);

    for (int i = 0; i < Capture_times; ++i) {
        vector<long> data;
        long time_stamp = 0;

        if (!urg.get_distance(data, &time_stamp)) {
            cout << "Urg_driver::get_distance(): " << urg.what() << endl;
            return 1;
        }

        print_data(urg, data, time_stamp);
    }

#if defined(URG_MSC)
    getchar();
#endif

    return 0;
}
```

Ejecutar el código:

```
$ sudo ./src/distance
```

## Bibliografía

* Librería del sensor URG-04LX:
    * https://sourceforge.net/projects/urgnetwork/files/urg_library/
