// Third party includes
#include <quazip.h>

// Other includes
#include "appreader.h"

AppReader::AppReader(QString appPath)
{
    QuaZip zip(appPath);
    zip.open(QuaZip::mdUnzip);

    zip.close();
}
