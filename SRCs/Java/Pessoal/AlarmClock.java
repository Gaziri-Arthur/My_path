package Pessoal;
import java.time.LocalDateTime;

public class AlarmClock {
    
    public LocalDateTime alarmtime;
    public String alarmSound;

    public AlarmClock(int year, int month, int day, int hour, int minute, String sound) {
        this.alarmtime = LocalDateTime.of(year, month, day, hour, minute, 0);
        this.alarmSound = sound;

    }
    
    public boolean isTimeToRing() {
        LocalDateTime now = LocalDateTime.now();
        return now.getYear() == alarmtime.getYear() && now.getMonthValue() == alarmtime.getMonthValue() && now.getDayOfMonth() == alarmtime.getDayOfMonth() && now.getHour() == alarmtime.getHour() && now.getMinute() == alarmtime.getMinute();
    }


}
