package gui_elements;

import communication.Bluetooth;
import configuration.Configuration;
import javafx.application.Application;
import javafx.application.Platform;
import scenes.MainScene;
import scenes.Scenes;
import timers.TimerCounter;

/**
 * Created by Robert Kłódka on 03.06.2016.
 */
public class UI {
    public static void changeUIState() {
        // check button status from device
        switch (Configuration.receivedData[1]) {
            case 49:
                // setting previous scene when button clicked (always main scene)
                if (Configuration.window.getScene() == Scenes.mainScene) {
                    Bluetooth.disconnect();
                    System.exit(0);
                } else {
                    Tile.deselectPanel(Scenes.mainScene, Configuration.activePanel);
                    Configuration.activePanel = MainScene.panel_0_tile;
                    Platform.runLater(() -> Scenes.setScene(MainScene.panel_0_tile));
                }
                break;
            default:
                break;
        }
        // check top plane from device
        switch (Configuration.receivedData[0]) {
            case 49:
                if (Configuration.window.getScene() == Scenes.mainScene) {
                    if (Configuration.activePanel != MainScene.panel_1_tile) {
                        Tile.deselectPanel(Scenes.mainScene, Configuration.activePanel);
                        Tile.selectPanel(MainScene.panel_1_tile, Scenes.scene1);
                        Configuration.activePanel = MainScene.panel_1_tile;
                        TimerCounter.stopCounting();
                        TimerCounter.startCounting(MainScene.panel_1_tile);
                    }
                }
                // same for the rest scenes
                break;
            case 50:
                if (Configuration.window.getScene() == Scenes.mainScene) {
                    Tile.deselectPanel(Scenes.mainScene, Configuration.activePanel);
                    Tile.selectPanel(MainScene.panel_2_tile, Scenes.scene1);
                    Configuration.activePanel = MainScene.panel_2_tile;
                    TimerCounter.stopCounting();
                    TimerCounter.startCounting(MainScene.panel_2_tile);
                }
                // same for the rest scenes
                break;
            case 51:
                if (Configuration.window.getScene() == Scenes.mainScene) {
                    Tile.deselectPanel(Scenes.mainScene, Configuration.activePanel);
                    Tile.selectPanel(MainScene.panel_3_tile, Scenes.scene1);
                    Configuration.activePanel = MainScene.panel_3_tile;
                    TimerCounter.stopCounting();
                    TimerCounter.startCounting(MainScene.panel_3_tile);
                }
                // same for the rest scenes
                break;
            case 52:
                if (Configuration.window.getScene() == Scenes.mainScene) {
                    Tile.deselectPanel(Scenes.mainScene, Configuration.activePanel);
                    Tile.selectPanel(MainScene.panel_4_tile, Scenes.scene1);
                    Configuration.activePanel = MainScene.panel_4_tile;
                    TimerCounter.stopCounting();
                    TimerCounter.startCounting(MainScene.panel_4_tile);
                }
                // same for the rest scenes
                break;
            case 53:
                if (Configuration.window.getScene() == Scenes.mainScene) {
                    Tile.deselectPanel(Scenes.mainScene, Configuration.activePanel);
                    Tile.selectPanel(MainScene.panel_5_tile, Scenes.scene1);
                    Configuration.activePanel = MainScene.panel_5_tile;
                    TimerCounter.stopCounting();
                    TimerCounter.startCounting(MainScene.panel_5_tile);
                }
                // same for the rest scenes
                break;
            default:
                Tile.deselectPanel(Scenes.mainScene, Configuration.activePanel);
                Configuration.activePanel = MainScene.panel_0_tile;
                TimerCounter.stopCounting();
                break;
        }
    }
}