import communication.Bluetooth;
import configuration.Configuration;
import scenes.*;

import javafx.scene.Scene;
import javafx.application.Application;
import javafx.stage.Stage;
import threads.BluetoothThread;

/**
 * Created by Robert Kłódka on 06.04.2016.
 */

public class Main extends Application {

    public static void main(String[] args) {
        // initialize configuration data
        new Configuration();
        // initialize all scenes data
        new MainScene();
        new Scene1();
        new Scene2();
        new Scene3();
        new Scene4();
        new Scene5();
        // initialize Bluetooth connection configuration
        new Bluetooth();

        // connect to Bluetooth device
        try {
            Bluetooth.connect();
        } catch (Exception e) {
            e.printStackTrace();
        }

        // send to Bluetooth device planes configuration (all planes active)
        Bluetooth.sendData("11111");

        // initialize Bluetooth listening thread
        Configuration.bluetoothThread = new BluetoothThread();
        Configuration.bluetoothThread.start();

        // launch application
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        // set primary stage
        Configuration.window = primaryStage;
        // set application title
        Configuration.window.setTitle("Cube");
        // set full screen to false
        Configuration.window.setFullScreen(false);
        // set window to maximized
        Configuration.window.setMaximized(true);

        // initialize scenes
        Scenes.mainScene = new Scene(MainScene.layout, Configuration.screenSize.getWidth(), Configuration.screenSize.getHeight());
        Scenes.scene1 = new Scene(Scene1.layout, Configuration.screenSize.getWidth(), Configuration.screenSize.getHeight());
        Scenes.scene2 = new Scene(Scene2.layout, Configuration.screenSize.getWidth(), Configuration.screenSize.getHeight());
        Scenes.scene3 = new Scene(Scene3.layout, Configuration.screenSize.getWidth(), Configuration.screenSize.getHeight());
        Scenes.scene4 = new Scene(Scene4.layout, Configuration.screenSize.getWidth(), Configuration.screenSize.getHeight());
        Scenes.scene5 = new Scene(Scene5.layout, Configuration.screenSize.getWidth(), Configuration.screenSize.getHeight());

        // set first scene
        Configuration.window.setScene(Scenes.mainScene);
        // show window
        Configuration.window.show();
    }
}