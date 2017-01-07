package threads;

import communication.Bluetooth;
import configuration.Configuration;

/**
 * Created by Robert Kłódka on 03.06.2016.
 */
public class BluetoothThread extends Thread {
    public void run() {
        while (true) {
            try {
                if (!Configuration.isSending) {
                    Bluetooth.getData();
                } else {
                    System.out.println("nie odbieram");
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }
}
