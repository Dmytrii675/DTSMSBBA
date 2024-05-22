class ExtantionDevice
{
private:
    int _priority;
    uint8_t _pin;
    bool _isEnable;
public:
    ExtantionDevice(int priority, uint8_t pin);
    void SetupEnable(bool isEnable);
    bool GetIsEnable();
    uint8_t GetPin();
    int GetPriority();
    ExtantionDevice();
};

ExtantionDevice::ExtantionDevice( int priority, uint8_t pin)
{
    this->_priority = priority;
    this->_pin = pin;
    this->_isEnable = false;
}

void ExtantionDevice::SetupEnable(bool isEnable)
{
    this->_isEnable = isEnable;
}

 bool ExtantionDevice::GetIsEnable()
{
    return this->_isEnable;
}

uint8_t ExtantionDevice::GetPin()
{
    return this->_pin;
}

int ExtantionDevice::GetPriority()
{
    return this->_priority;
}

ExtantionDevice::ExtantionDevice()
{
    this->_pin = UINT8_MAX;
    this ->_isEnable = false;
}