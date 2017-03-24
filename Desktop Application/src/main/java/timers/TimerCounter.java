package timers;

import configuration.Configuration;
import gui_elements.Tile;
import javafx.application.Platform;
import scenes.Scenes;

import java.util.Timer;
import java.util.TimerTask;

/**
 * Created by Robert Kłódka on 04.06.2016.
 */
public class TimerCounter {

    private static float i = 0.0f;
    private static Timer timer;

     public static void startCounting(Tile tile) {
        timer = new Timer();
        TimerTask timerTask = new TimerTask() {
            @Override
            public void run() {
                Configuration.isTimerRunning = true;
                i = i + 0.5f;
                System.out.println("Timer " + i);
                if (i >= 3) {
                    stopCounting();
                    i = 0.0f;
                    Platform.runLater(() -> Scenes.setScene(tile));
                }
            }
        };
        timer.schedule(timerTask,500,500);
    }

    public static void stopCounting() {
        if (Configuration.isTimerRunning) {
            timer.cancel();
            timer.purge();
            i = 0.0f;
            Configuration.isTimerRunning = false;
        }
    }

}
