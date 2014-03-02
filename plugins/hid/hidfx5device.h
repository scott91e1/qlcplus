/*
  Q Light Controller Plus
  hidfx5device.h

  Copyright (c) Massimo Callegari
                Florian Euchner

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef HIDFX5DEVICE_H
#define HIDFX5DEVICE_H

#include <QObject>
#include <QFile>
#include <QHash>

#include <sys/ioctl.h>
#include <linux/input.h>
#include <linux/types.h>

#include "hiddevice.h"

#define FX5_DMX_INTERFACE_VENDOR_ID 0x4B4
#define FX5_DMX_INTERFACE_PRODUCT_ID 0xF1F
#define FX5_DMX_INTERFACE_VENDOR_ID_2 0x16C0
#define FX5_DMX_INTERFACE_PRODUCT_ID_2 0x88B

class HIDEventDevice;
class HID;

/*****************************************************************************
 * HIDEventDevice
 *****************************************************************************/

class HIDFX5Device : public HIDDevice
{
    Q_OBJECT

public:
    HIDFX5Device(HID* parent, quint32 line, const QString& name, const QString& path);
    virtual ~HIDFX5Device();

protected:
    /** Initialize the device, find out its capabilities etc. */
    void init();

    /** @reimp */
    bool hasInput() { return true; }

    /** @reimp */
    bool hasOutput() { return true; }

    /*********************************************************************
     * File operations
     *********************************************************************/
public:
    /** @reimp */
    bool open();

    /** @reimp */
    void close();

    /** @reimp */
    QString path() const;

    /** @reimp */
    bool readEvent();

    /*********************************************************************
     * Device info
     *********************************************************************/
public:
    /** @reimp */
    QString infoText();

    /*********************************************************************
     * Input data
     *********************************************************************/
public:
    /** @reimp */
    void feedBack(quint32 channel, uchar value);
};

#endif
