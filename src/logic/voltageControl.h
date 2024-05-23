#include "ExtantionDevice.h"
#define MAX_SIZE 11
class Devices
{
private:
    ExtantionDevice _devices[MAX_SIZE];
    int size;
    int offedCount;
    bool Validate(ExtantionDevice devices[]);
    void bubbleSort(ExtantionDevice *devices, int n);
    ExtantionDevice *GetForOff();

public:
    int GetOffedCount();
    void SetupOffedCount(int iter);
    Devices(ExtantionDevice devices[], int s);
    ExtantionDevice *GetNextPriorityForOff();
    ExtantionDevice *GetForInitDevice();
    ExtantionDevice *GetDeviceByPriorityOn();
};

bool Devices::Validate(ExtantionDevice devices[])
{
    this->bubbleSort(devices, this->size);
    for (int i = 0; i < this->size; i++)
    {
        if (devices[i].GetPriority() != i + 1)
            return false;
    }

    return true;
}

int Devices::GetOffedCount()
{
    return this->offedCount;
}

inline void Devices::SetupOffedCount(int iter)
{
    if (iter == 1 || iter == -1)
    {
        this->offedCount += iter;
    }
}

Devices::Devices(ExtantionDevice devices[], int s)
{
    if (s <= MAX_SIZE)
    {
        this->size = s;
        this->offedCount = s;
        if (this->Validate(devices))
        {
            for (int i = 0; i < s; i++)
            {
                this->_devices[i] = devices[i];
            }
        }
    }
}

ExtantionDevice *Devices::GetNextPriorityForOff()
{
    return this->GetForOff();
}

ExtantionDevice *Devices::GetForInitDevice()
{

    ExtantionDevice *dev;
    for (int i = 0; i < this->size; i++)
    {
        if (this->_devices[i].GetIsEnable() == false)
        {
            dev = &_devices[i];
            break;
        }
    }

    return dev;
}

inline ExtantionDevice *Devices::GetDeviceByPriorityOn()
{
    ExtantionDevice *res;
    for (int i = 0; i < size; i++)
    {
        if (this->_devices[i].GetIsEnable() == false)
        {
            res = &_devices[i];
            break;
        }
    }
    return res;
}

void Devices::bubbleSort(ExtantionDevice *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].GetPriority() > arr[j + 1].GetPriority())
            {
                // swap arr[j] and arr[j+1]
                ExtantionDevice temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

ExtantionDevice *Devices::GetForOff()
{
    ExtantionDevice *res;
    for (int i = this->size; i != -1; i--)
    {
        if (this->_devices[i].GetIsEnable() == true)
        {
            res = &_devices[i];
            break;
        }
    }
    return res;
}