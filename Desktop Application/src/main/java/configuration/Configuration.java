package configuration;

import gui_elements.Tile;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import threads.BluetoothThread;

import java.awt.*;

/**
 * Created by Robert Kłódka on 09.04.2016.
 */

public class Configuration {

    //region GLOBAL VARIABLES

        public static Stage window;

        public static Dimension screenSize;
        public static double tilePadding;

        public static Color RED = new Color(1.0, 0.0, 0.0, 1.0);
        public static Color GREEN = new Color(0.0, 1.0, 0.0, 1.0);
        public static Color BLUE = new Color(0.0, 0.0, 1.0, 1.0);
        public static Color YELLOW = new Color(1.0, 1.0, 0.0, 1.0);
        public static Color PURPLE = new Color(0.5, 0.0, 0.5, 1.0);
        public static Color TRANSPARENT = new Color(0.0, 0.0, 0.0, 0.0);

        public static String scene1Tile1Text = "Internet";

        public static Tile activePanel;
        public static boolean isTimerRunning = false;

        public static BluetoothThread bluetoothThread;
        public static boolean isSending = false;

        public static byte receivedData[];

    //endregion

    public Configuration() {
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        screenSize = toolkit.getScreenSize();
        tilePadding = screenSize.getWidth()/8;
    }
}