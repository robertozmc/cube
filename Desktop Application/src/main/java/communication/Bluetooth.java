package communication;

import configuration.Configuration;
import gui_elements.UI;

import java.io.*;
import javax.microedition.io.Connector;
import javax.microedition.io.StreamConnection;

public class Bluetooth {
    //region Variables

    private static StreamConnection streamConnection;
    private static OutputStream os;
    private static InputStream is;

    //endregion

    public static void connect() {
        // connect to device

        // device bluetooth address
        String deviceURL = "btspp://98D33130854A:1;authenticate=false;encrypt=false;master=false";
        try {
            streamConnection = (StreamConnection) Connector.open(deviceURL);
            os = streamConnection.openOutputStream();
            is = streamConnection.openInputStream();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void disconnect() {
        // disconnect from device
        try {
            os.close();
            is.close();
            streamConnection.close();
        } catch (Exception e) {
           e.printStackTrace();
        }
    }

    public static void sendData(String activePlanes) {
        // send active planes configuration
        try {
            os.write(activePlanes.getBytes());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void getData() {
        // get plane on top and button status
        try {
            DataInputStream din = new DataInputStream(is);
            byte[] buffer = new byte[2];
            din.readFully(buffer);
            Configuration.receivedData = buffer;
        } catch (Exception e) {
            e.printStackTrace();
        }

        UI.changeUIState();
    }
}