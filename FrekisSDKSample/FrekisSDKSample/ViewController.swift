//
//  ViewController.swift
//  FrekisDemo
//
//  Created by Hitesh Prajapati on 22/07/20.
//  Copyright © 2020 Bhargav. All rights reserved.
//

import UIKit
import FrekisFramework
//import NVActivityIndicatorView
class ViewController: UIViewController {
    var isAuth : Bool = false
    var isConnct : Bool = false
    
    var isUnlock : Bool = false
    var isAlarm : Bool = false
    //MARK:- IBOutlets
    @IBOutlet weak var lblStatus : UILabel!
    @IBOutlet weak var lblKey : UILabel!
    @IBOutlet weak var lblLock : UILabel!
    @IBOutlet weak var txtKey : UITextField!
    
    @IBOutlet weak var txtDetails : UITextView!
    
    @IBOutlet weak var txtLockID : UITextField!
    @IBOutlet weak var btnAlarm : UIButton! {
        didSet{
            btnAlarm.setTitle("Enable Alarm", for: .normal)
            btnAlarm.setTitle("Disable Alarm", for: .selected)
            btnAlarm.setTitleColor(.black, for: .normal)
            btnAlarm.setTitleColor(.red, for: .selected)
        }
    }
    @IBOutlet weak var btnAuth : UIButton! {
        didSet{
            btnAuth.setTitle("Authorized", for: .normal)
            btnAuth.setTitle("Cancel", for: .selected)
            btnAuth.setTitleColor(.black, for: .normal)
            btnAuth.setTitleColor(.red, for: .selected)
        }
    }
    @IBOutlet weak var btnConnect : UIButton! {
        didSet{
            btnConnect.setTitle("Connect", for: .normal)
            btnConnect.setTitle("Disconnect", for: .selected)
            btnConnect.setTitleColor(.black, for: .normal)
            btnConnect.setTitleColor(.red, for: .selected)
        }
    }
    @IBOutlet weak var btnUnLock : UIButton! {
        didSet{
            btnUnLock.setTitle("Unlock", for: .normal)
            btnUnLock.setTitle("Lock", for: .selected)
            btnUnLock.setTitleColor(.black, for: .normal)
            btnUnLock.setTitleColor(.black, for: .selected)
        }
    }
    
    
    //MARK:- Variables
    let testSecretKey = "0a02a1ed-b9ce-4500-aec4-7a48db13eba3"
    let testLockID  =   "0787909A7703B6F9"
    let unlockLocation = CLLocationCoordinate2D(latitude: 23.082653, longitude: 72.524578)
    let lockLocation = CLLocationCoordinate2D(latitude: 23.070490, longitude: 72.522692)
    var isDeviceConnected : Bool = false
    
    var get_lock_id : String = ""
    
    var frekis : Frekis?
    //MARK:-
    override func viewDidLoad() {
        lblStatus.text = ""
        self.txtKey.text = testSecretKey
        self.txtLockID.text = testLockID
        self.hideLockPart()
        frekis = Frekis.getInstance()
        frekis!.delegate = self
    }
    
    //MARK:- Framework functions
    //1. Get users detail from secret_key
    @IBAction func click_Auth(_ sender : UIButton){
        
        if isAuth {
            
            self.startLoader(message: "Unauthorization....")
            self.btnAuth.isSelected = false
            lblStatus.text = "Disconnecting.."
            frekis!.disconnect(lock_id: self.txtLockID.text!)
            self.hideLockPart()
            self.btnConnect.isSelected = false
            
            self.btnUnLock.isHidden = true
            self.isConnct = false
            self.isAuth = false
        }else{
            self.startLoader(message: "Authorization....")
            lblStatus.text = "Please wait.."
            frekis!.setAuthKey(token: self.txtKey.text!) { (isSuccess) in
                self.lblStatus.text = "Get detail \(isSuccess ? "success.." : "failed..")"
                print(isSuccess)
                self.hideLoader()
                self.isAuth = isSuccess
                if isSuccess {
                    
                    self.btnAuth.isSelected = true
                    
                    self.showLockPart()
                }
            }
        }
    }
    
    func showLockPart(){
        self.lblLock.isHidden = false
        self.txtLockID.isHidden = false
        self.btnConnect.isHidden = false
        
    }
    
    func hideLockPart(){
        self.lblLock.isHidden = true
        self.txtLockID.isHidden = true
        self.btnConnect.isHidden = true
        self.btnUnLock.isHidden = true
        self.btnAlarm.isHidden = true
    }
    @IBAction func click_Connect(_ sender : UIButton){
        
        if isConnct {
            self.btnConnect.isSelected = false
            lblStatus.text = "Disconnecting.."
            self.startLoader(message: "Disconnecting....")
            frekis!.disconnect(lock_id: self.txtLockID.text!)
            self.btnUnLock.isHidden = true
            self.btnAlarm.isHidden = true
            self.btnAlarm.isSelected = false
            self.isConnct = false
            self.isAlarm = false
        }else{
            self.startLoader(message: "Connecting....")
            lblStatus.text = "Scanning.."
            frekis!.connect(lock_id: self.txtLockID.text!) { (isConnected,lock_id,asset) in
                self.hideLoader()
                self.isConnct = isConnected
                self.get_lock_id = lock_id
                self.lblStatus.text = "Asset connection \(isConnected ? "success.." : "failed..")"
                if isConnected {
                    self.isDeviceConnected = isConnected
                    
                    self.btnConnect.isSelected = true
                    self.btnUnLock.isHidden = false
                    self.btnAlarm.isHidden = false
                    self.isAlarm = asset!.isVibrationAlert
                    self.btnAlarm.isSelected = self.isAlarm
                    if let data = asset {
                        self.txtDetails.text = "\(data)"
                    }
                }
                
            }
            
        }
    }
    @IBAction func click_UnLock(_ sender : UIButton){
        self.startLoader(message: "Unlocking asset..")
        lblStatus.text = "Unlocking asset.."
        frekis!.unlockAsset(lock_id: self.get_lock_id, location: unlockLocation) { (unlockStatus,asset) in
            self.hideLoader()
            
            if unlockStatus {
                self.isUnlock = true
                self.btnUnLock.isHidden = true
                
                
            }
            self.lblStatus.text = "Asset unlock \(unlockStatus ? "success.." : "failed..")"
            print("Device unlock status = ", unlockStatus)
            
            if let data = asset {
                self.txtDetails.text = "\(data)"
            }
        }
        
    }
    @IBAction func click_Alarm(_ sender : UIButton){
        if self.isAlarm {
            frekis!.setVibration(isOn: false) { (status,asset) in
                if status == 0 {
                    print("Vibration Off ")
                    self.isAlarm = false
                    sender.isSelected = false
                }else if status == 1 {
                    self.isAlarm = true
                    print("Vibration On ")
                    sender.isSelected = true
                }else if status == 2{
                    print("Unable to update the alarm ")
                }else if status == 3{
                     print("Connected device instance not found, please reconnect device to continue.")
                }
                if let data = asset {
                    self.txtDetails.text = "\(data)"
                }
            }
        }else{
            frekis!.setVibration(isOn: true) { (status,asset) in
                if status == 0 {
                    self.isAlarm = false
                    print("Vibration Off ")
                    sender.isSelected = false
                }else if status == 1 {
                    self.isAlarm = true
                    print("Vibration On ")
                    sender.isSelected = true
                }else if status == 2{
                    print("Unable to update the alarm ")
                }else if status == 3{
                     print("Connected device instance not found, please reconnect device to continue.")
                }
                if let data = asset {
                    self.txtDetails.text = "\(data)"
                }

            }
        }
    }
    @IBAction func getUserDetail(_ sender : UIButton){
        lblStatus.text = "Please wait.."
        frekis!.setAuthKey(token: self.txtKey.text!) { (isSuccess) in
            self.lblStatus.text = "Get detail \(isSuccess ? "success.." : "failed..")"
            print(isSuccess)
        }
    }
    
    //2. Try scan and connect device
    @IBAction func connectDevice(_ sender : UIButton){
        if !isDeviceConnected{
            lblStatus.text = "Scanning.."
            frekis!.connect(lock_id: self.txtLockID.text!) { (isConnected,lock_id,asset) in
                self.isDeviceConnected = isConnected
                self.get_lock_id = lock_id
                self.lblStatus.text = "Asset connection \(isConnected ? "success.." : "failed..")"
            }
        }
        else{
            lblStatus.text = "Device is already connected."
            print("Device is already connected.")
        }
    }
    
    //3. Unlock device, which will unlock the device and start ride,
    @IBAction func unlockDevice(_ sender : UIButton){
        lblStatus.text = "Unlocking asset.."
        frekis!.unlockAsset(lock_id: self.get_lock_id, location: unlockLocation) { (unlockStatus,asset) in
            self.lblStatus.text = "Asset unlock \(unlockStatus ? "success.." : "failed..")"
            print("Device unlock status = ", unlockStatus)
        }
    }
    
    //4. Lock device, which will end ride
    @IBAction func lockDevice(_ sender : UIButton){
        lblStatus.text = "Locking asset.."
        frekis!.lockAsset(lock_id: self.get_lock_id, location: lockLocation) { (lockStatus) in
            print("Device lock status = ", lockStatus)
        }
    }
    
    //5. Disconnect lock
    @IBAction func disconnect(_ sender : UIButton){
        lblStatus.text = "Disconnecting.."
        frekis!.disconnect(lock_id: self.txtLockID.text!)
    }
    
    
}

//MARK:- Delegate
extension ViewController : FrekisDelegate{
    
    
    func deviceManuallyLocked(_ data: AssetModel?) {
        if self.isAuth && self.isConnct && self.isUnlock {
            lblStatus.text = "Locked"
            self.startLoader(message: "Locking asset..")
            frekis!.lockAsset(lock_id: self.txtLockID.text!, location: lockLocation) { (lockStatus) in
                print("Device lock status = ", lockStatus)
                self.hideLoader()
                if lockStatus {
                    self.isUnlock = false
                    DispatchQueue.main.async {
                        self.lblStatus.text = "Locked"
                        self.btnUnLock.isHidden = false
                    }
                    
                }
            }
        }
        
        if let asset = data {
            self.txtDetails.text = "\(asset)"
        }

        
    }
    
    func deviceDisconnected() {
        if self.isAuth {
            lblStatus.text = "Disconnected.."
        }else{
            lblStatus.text = "Unauthorized.."
        }
        //handle disconnection..
        
        self.hideLoader()
    }
    
}

extension UIViewController {
    
    func hideLoader(){
        //        stopAnimating()
        
    }
    
    func startLoader(message : String? = nil){
        //        startAnimating(CGSize(width: 50, height: 50), message: message, type: .ballPulseSync, color: .white, padding: 0)
    }
    
}
