/**
 * Editor a interpret hierarchicky strukturovaných funkčních bloků
 * @brief   Core reprezentation of socket
 *
 * @authors Jakub Komárek (xkomar33), Violeta Koleva (xkolev00)
 * @date    07-05-2021
 * @version 1.0
 */
#ifndef PORTSOCKET_H
#define PORTSOCKET_H

#include <QObject>
#include <QDebug>

#include "port.h"

class portSocket : public block {
    Q_OBJECT
public:
    portSocket(port * imitating);
    ~portSocket();
    /**
     * adding imitating port to block
     */
    void addPort();
    port * imitating{nullptr};
    port * viewedPort{nullptr};
    /**
     * when imitating port changed, update function is caled
     */
    void update();

};

#endif // PORTSOCKET_H
