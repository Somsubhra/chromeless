// Qt includes
#include <QDebug>

// Other includes
#include "application.h"
#include "factory.h"

int main(int argc, char** argv) {

    Application app(argc, argv);

    QString appPackage = app.appPackage();

    Factory(argc, argv, appPackage);

    return app.exec();
}
