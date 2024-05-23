
enum TemperatureStatus{
    Low,
    Medium, 
    Critical
};


TemperatureStatus getTemperatureStatus(float temperature){
    if(temperature < 19)
    {
        return TemperatureStatus::Low;
    }else if(temperature >= 19 && temperature <= 40){
        return TemperatureStatus::Medium;
    }
    return TemperatureStatus::Critical;
};