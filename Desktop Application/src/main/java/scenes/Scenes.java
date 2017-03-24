package scenes;

import communication.Bluetooth;
import configuration.Configuration;
import gui_elements.Tile;
import javafx.scene.Scene;
import threads.BluetoothThread;

/**
 * Created by Robert Kłódka on 09.04.2016.
 */
public class Scenes {

    //region Scene list

        // Level 1 scene
        public static Scene mainScene;

        // Level 2 scenes
        public static Scene scene1;
        public static Scene scene2;
        public static Scene scene3;
        public static Scene scene4;
        public static Scene scene5;

    //endregion

        public static void setScene(Tile tile) {
            if (Configuration.window.getScene() == Scenes.mainScene) {
                if (tile == MainScene.panel_1_tile) {
                    Configuration.window.setScene(Scenes.scene1);
                    Bluetooth.sendData("11111");
                }
                if (tile == MainScene.panel_2_tile) {
                    Configuration.window.setScene(Scenes.scene2);
                    Bluetooth.sendData("11111");
                }
                if (tile == MainScene.panel_3_tile) {
                    Configuration.window.setScene(Scenes.scene3);
                    Bluetooth.sendData("11111");
                }
                if (tile == MainScene.panel_4_tile) {
                    Configuration.window.setScene(Scenes.scene4);
                    Bluetooth.sendData("11100");
                }
                if (tile == MainScene.panel_5_tile) {
                    Configuration.window.setScene(Scenes.scene5);
                    Bluetooth.sendData("11111");
                }
            } else if (Configuration.window.getScene() == Scenes.scene1) {
                if (tile == MainScene.panel_0_tile) {
                    Configuration.window.setScene(Scenes.mainScene);
                    Bluetooth.sendData("11111");
                }
                //obsluga kolejnego poziomu
            } else if (Configuration.window.getScene() == Scenes.scene2) {
                if (tile == MainScene.panel_0_tile) {
                    Configuration.window.setScene(Scenes.mainScene);
                }
                // obsluga kolejnego poziomu
            } else if (Configuration.window.getScene() == Scenes.scene3) {
                if (tile == MainScene.panel_0_tile) {
                    Configuration.window.setScene(Scenes.mainScene);
                }
                // obsluga kolejnego poziomu
            } else if (Configuration.window.getScene() == Scenes.scene4) {
                if (tile == MainScene.panel_0_tile) {
                    Configuration.window.setScene(Scenes.mainScene);
                }
                // obsluga kolejnego poziomu
            } else if (Configuration.window.getScene() == Scenes.scene5) {
                if (tile == MainScene.panel_0_tile) {
                    Configuration.window.setScene(Scenes.mainScene);
                }
                // obsluga kolejnego poziomu
            }
        }

}
