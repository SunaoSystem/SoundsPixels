#include "testApp.h"
#include "iostream.h"

void testApp::setup () {
    
    ofSetLogLevel(OF_LOG_NOTICE);
    
    //まずセットアップ
    kinect.setup();
    indicator.setup();
    metronome.setup();
    for(int i=1;i <= num_dp_x; i++){
        for(int j=1; j<= num_dp_y; j++){
            dancePixel[i][j].init((i-1) * int(dots_width/(num_dp_x-1)),
                                  (j-1) * int(dots_height/(num_dp_y-1)),
                                  10);
        }
    }
    
    kinect.setRegister(TRUE);
    kinect.setMirror(TRUE);
    
    //イメージジェネレータなど
    kinect.addImageGenerator();
    kinect.addDepthGenerator();
    kinect.addUserGenerator();
    //スタート
    kinect.start();
    
    
    //USERを前もって宣言（可能？）
      /* for (XnUserID nID = 1; nID <= kinect.getMaxNumUsers(); nID++){
           ofxOpenNIUser & user = kinect.getTrackedUser(nID);
           user.setUseMaskTexture(true);
           user.setUsePointCloud(true);
           //user.setUseAutoCalibration(false); // defualts to true; set to false to force pose detection
           //user.setLimbDetectionConfidence(0.9f); // defaults 0.3f
           user.setPointCloudDrawSize(2);
           user.setPointCloudResolution(1);
        }*/
    
    //プロパティ
    kinect.setMaxNumUsers(3);
    kinect.setUseMaskTextureAllUsers(true);
    
    
    
    trg = TRUE;
    
    
    //loadSound
    sound[1][24].loadSound("mp3/01_01.mp3");
    sound[1][23].loadSound("mp3/01_02.mp3");
    sound[1][22].loadSound("mp3/01_03.mp3");
    sound[1][21].loadSound("mp3/01_04.mp3");
    sound[1][20].loadSound("mp3/01_05.mp3");
    sound[1][19].loadSound("mp3/01_06.mp3");
    sound[1][18].loadSound("mp3/01_07.mp3");
    sound[1][17].loadSound("mp3/01_08.mp3");
    sound[1][16].loadSound("mp3/01_09.mp3");
    sound[1][15].loadSound("mp3/01_10.mp3");
    sound[1][14].loadSound("mp3/01_11.mp3");
    sound[1][13].loadSound("mp3/01_12.mp3");
    sound[1][12].loadSound("mp3/01_13.mp3");
    sound[1][11].loadSound("mp3/01_14.mp3");
    sound[1][10].loadSound("mp3/01_15.mp3");
    sound[1][9].loadSound( "mp3/01_16.mp3");
    sound[1][8].loadSound( "mp3/01_17.mp3");
    sound[1][7].loadSound( "mp3/01_18.mp3");
    sound[1][6].loadSound( "mp3/01_19.mp3");
    sound[1][5].loadSound( "mp3/01_20.mp3");
    sound[1][4].loadSound( "mp3/01_21.mp3");
    sound[1][3].loadSound( "mp3/01_22.mp3");
    sound[1][2].loadSound( "mp3/01_23.mp3");
    sound[1][1].loadSound( "mp3/01_24.mp3");
    
    sound[2][24].loadSound("mp3/02_01.mp3");
    sound[2][23].loadSound("mp3/02_02.mp3");
    sound[2][22].loadSound("mp3/02_03.mp3");
    sound[2][21].loadSound("mp3/02_04.mp3");
    sound[2][20].loadSound("mp3/02_05.mp3");
    sound[2][19].loadSound("mp3/02_06.mp3");
    sound[2][18].loadSound("mp3/02_07.mp3");
    sound[2][17].loadSound("mp3/02_08.mp3");
    sound[2][16].loadSound("mp3/02_09.mp3");
    sound[2][15].loadSound("mp3/02_10.mp3");
    sound[2][14].loadSound("mp3/02_11.mp3");
    sound[2][13].loadSound("mp3/02_12.mp3");
    sound[2][12].loadSound("mp3/02_13.mp3");
    sound[2][11].loadSound("mp3/02_14.mp3");
    sound[2][10].loadSound("mp3/02_15.mp3");
    sound[2][9].loadSound( "mp3/02_16.mp3");
    sound[2][8].loadSound( "mp3/02_17.mp3");
    sound[2][7].loadSound( "mp3/02_18.mp3");
    sound[2][6].loadSound( "mp3/02_19.mp3");
    sound[2][5].loadSound( "mp3/02_20.mp3");
    sound[2][4].loadSound( "mp3/02_21.mp3");
    sound[2][3].loadSound( "mp3/02_22.mp3");
    sound[2][2].loadSound( "mp3/02_23.mp3");
    sound[2][1].loadSound( "mp3/02_24.mp3");
    
    sound[3][24].loadSound("mp3/03_01.mp3");
    sound[3][23].loadSound("mp3/03_02.mp3");
    sound[3][22].loadSound("mp3/03_03.mp3");
    sound[3][21].loadSound("mp3/03_04.mp3");
    sound[3][20].loadSound("mp3/03_05.mp3");
    sound[3][19].loadSound("mp3/03_06.mp3");
    sound[3][18].loadSound("mp3/03_07.mp3");
    sound[3][17].loadSound("mp3/03_08.mp3");
    sound[3][16].loadSound("mp3/03_09.mp3");
    sound[3][15].loadSound("mp3/03_10.mp3");
    sound[3][14].loadSound("mp3/03_11.mp3");
    sound[3][13].loadSound("mp3/03_12.mp3");
    sound[3][12].loadSound("mp3/03_13.mp3");
    sound[3][11].loadSound("mp3/03_14.mp3");
    sound[3][10].loadSound("mp3/03_15.mp3");
    sound[3][9].loadSound( "mp3/03_16.mp3");
    sound[3][8].loadSound( "mp3/03_17.mp3");
    sound[3][7].loadSound( "mp3/03_18.mp3");
    sound[3][6].loadSound( "mp3/03_19.mp3");
    sound[3][5].loadSound( "mp3/03_20.mp3");
    sound[3][4].loadSound( "mp3/03_21.mp3");
    sound[3][3].loadSound( "mp3/03_22.mp3");
    sound[3][2].loadSound( "mp3/03_23.mp3");
    sound[3][1].loadSound( "mp3/03_24.mp3");
    
    sound[4][24].loadSound("mp3/04_01.mp3");
    sound[4][23].loadSound("mp3/04_02.mp3");
    sound[4][22].loadSound("mp3/04_03.mp3");
    sound[4][21].loadSound("mp3/04_04.mp3");
    sound[4][20].loadSound("mp3/04_05.mp3");
    sound[4][19].loadSound("mp3/04_06.mp3");
    sound[4][18].loadSound("mp3/04_07.mp3");
    sound[4][17].loadSound("mp3/04_08.mp3");
    sound[4][16].loadSound("mp3/04_09.mp3");
    sound[4][15].loadSound("mp3/04_10.mp3");
    sound[4][14].loadSound("mp3/04_11.mp3");
    sound[4][13].loadSound("mp3/04_12.mp3");
    sound[4][12].loadSound("mp3/04_13.mp3");
    sound[4][11].loadSound("mp3/04_14.mp3");
    sound[4][10].loadSound("mp3/04_15.mp3");
    sound[4][9].loadSound( "mp3/04_16.mp3");
    sound[4][8].loadSound( "mp3/04_17.mp3");
    sound[4][7].loadSound( "mp3/04_18.mp3");
    sound[4][6].loadSound( "mp3/04_19.mp3");
    sound[4][5].loadSound( "mp3/04_20.mp3");
    sound[4][4].loadSound( "mp3/04_21.mp3");
    sound[4][3].loadSound( "mp3/04_22.mp3");
    sound[4][2].loadSound( "mp3/04_23.mp3");
    sound[4][1].loadSound( "mp3/04_24.mp3");

}

void testApp::update () {
    
    kinect.update();
    indicator.update();
    metronome.update();
    
    //dancePixelの情報をリセットする
    for(int i=1; i<=num_dp_x; i++){
        for(int j=1; j<=num_dp_y; j++){
            dancePixel[i][j].reset();
        }
    }
    
    //isTracking 初期化
    for(int num=1; num<=10; num++){
        isTrackingUser[FALSE];
    }
    
    int numUsers = kinect.getNumTrackedUsers();
    
    if(numUsers > 0){
        for(int nID=0; nID<numUsers; nID++){
        
            //初期症状(すべてのドットがユーザー認識する)解消フラグ
            user_FALSE_flg = 0;
        
            ofxOpenNIUser & user = kinect.getTrackedUser(nID);
            user.setMaskPixelFormat(OF_PIXELS_MONO);
            if(user.isTracking() == TRUE){
                //IDをメモリー
                int userID = user.getXnID();
                //メモリーしたIDのisTrackingUserにTRUEを代入
                isTrackingUser[userID] = TRUE;
                ofPixels maskPixels = user.getMaskPixels();
                for(int i=1; i<=num_dp_x; i++){
                    for(int j=1; j<=num_dp_y; j++){
            
                    ofColor mColor = maskPixels.getColor((i-1)*int(kinect.getWidth()/num_dp_x),(j-1)*int(kinect.getHeight()/num_dp_y));
                    
                        if(mColor.b != 0){
                            dancePixel[i][j].setUser(TRUE,userID);
                        }
                        else{
                            dancePixel[i][j].setUser(FALSE,userID);
                            user_FALSE_flg++;
                        }
                    }
                }
                
                
                //isSkeltonを入手→もし変化があったらTrackingをStop
                if(skeleton_flg[userID] == TRUE && user.isSkeleton() == FALSE){
                    stop_skeleton_flg [userID] = TRUE;
                }
                skeleton_flg[userID] = user.isSkeleton();
                
                if(stop_skeleton_flg[userID] == TRUE){
                    kinect.resetUserTracking(userID);
                    stop_skeleton_flg[userID] = FALSE;
                }
                
                
                //初期症状(すべてのドットがユーザー認識する)解消
                if(user_FALSE_flg == 0){
                    for(int i=1; i<=num_dp_x; i++){
                        for(int j=1; j<=num_dp_y; j++){
                            dancePixel[i][j].setUser(FALSE,userID);
                        }
                    }
                }
            }
        }
        
        for(int num=0; num<10; num++){
            //isTrackingUserがFALSEの場合、ユーザー認識を解消する
            if(isTrackingUser[num] == FALSE){
                for(int i=1; i<=num_dp_x; i++){
                    for(int j=1; j<=num_dp_y; j++){
                        dancePixel[i][j].setUser(FALSE,num);
                    }
                }
            }
        }
    }
    
    
    for(int i=1; i<=num_dp_x; i++){
        for(int j=1; j<=num_dp_y; j++){
            updateMetronomeStatus(i,j);
           // updateIndicatorFlgStatus(i,j);
            dancePixel[i][j].update();
        }
    }
}

void testApp::updateIndicatorFlgStatus(int i,int j){
    if(dancePixel[i][j].getSetupX() < indicator.getX()){
        dancePixel[i][j].setNowIndicatorFlg(TRUE);
    }
    if(indicator.getX() == 0){
        dancePixel[i][j].setNowIndicatorFlg(FALSE);
    }
}

void testApp::updateMetronomeStatus(int i,int j){
    if(i == metronome.getBeat()){
        dancePixel[i][j].setTargetWidth(30);
        dancePixel[i][j].setTargetHeight(30);
    }
    
    if(i < metronome.getBeat()){
        dancePixel[i][j].setNowIndicatorFlg(TRUE);
    }
    if(metronome.getJustBeat() == 1){
        dancePixel[i][j].setNowIndicatorFlg(FALSE);
    }
}

void testApp::draw () {
    
    // numUsers = 認識されたユーザー
    
    ofBackground(0);
    
    ofPushMatrix();
    ofTranslate((ofGetWidth()-dots_width)/2,(ofGetHeight()-dots_height)/2);
    
    for(int i = 1; i <= num_dp_x; i++){
        for(int j = 1; j <= num_dp_y; j++){
            //ofSetRectMode(OF_RECTMODE_CENTER);
            dancePixel[i][j].draw();
        }
    }
    ofPopMatrix();
    
    playSound();
}

void testApp::playSound(){
    if(metronome.getJustBeat() != 0){
        for(int j = 1; j <= num_dp_y; j++){
            if(dancePixel[metronome.getJustBeat()][j].getSoundUserFlg() != 0){
                int user_num = dancePixel[metronome.getJustBeat()][j].getSoundUserFlg();
                sound[user_num][j].play();
            }
        }
    }
}

void testApp::exit(){
    kinect.stop();
}

void testApp::keyPressed (int key) {
    if (key == 'f')
    {
        //フルスクリーン on/off の切り替え
        ofToggleFullscreen();
    }
    if (key == 'r'){
        /*kinect.resetUserTracking(0,TRUE);
        kinect.resetUserTracking(1,TRUE);
        kinect.resetUserTracking(2,TRUE);
        kinect.resetUserTracking(3,TRUE);
        kinect.resetUserTracking(4,TRUE);*/
        kinect.removeUserGenerator();
        kinect.setup();
        kinect.addUserGenerator();
        kinect.start();
    }
}
void testApp::keyReleased (int key) {}
void testApp::mouseMoved (int x, int y) {}
void testApp::mouseDragged (int x, int y, int button){}
void testApp::mousePressed (int x, int y, int button) {}
void testApp::mouseReleased (int x, int y, int button){}
void testApp::windowResized (int w, int h){}
void testApp::dragEvent (ofDragInfo dragInfo) {}
void testApp::gotMessage (ofMessage msg) {}