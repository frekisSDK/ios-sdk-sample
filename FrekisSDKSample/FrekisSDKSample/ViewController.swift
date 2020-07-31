//
//  ViewController.swift
//  FrekisDemo
//
//  Created by Hitesh Prajapati on 22/07/20.
//  Copyright © 2020 Bhargav. All rights reserved.
//

import UIKit
import FrekisFramework

class ViewController: UIViewController {
    var isAuth : Bool = false
    var isConnct : Bool = false
    
    var isUnlock : Bool = false
    //MARK:- IBOutlets
    @IBOutlet weak var lblStatus : UILabel!
    @IBOutlet weak var lblKey : UILabel!
    @IBOutlet weak var lblLock : UILabel!
    @IBOutlet weak var txtKey : UITextField!
    
    @IBOutlet weak var txtLockID : UITextField!
    
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
    let testSecretKey = ""
    let testLockID  =   ""
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
            self.btnAuth.isSelected = false
            lblStatus.text = "Disconnecting.."
            frekis!.disconnect(lock_id: self.txtLockID.text!)
            self.hideLockPart()
        }else{
          
            lblStatus.text = "Please wait.."
            frekis!.setAuthKey(token: self.txtKey.text!) { (isSuccess) in
                self.lblStatus.text = "Get detail \(isSuccess ? "success.." : "failed..")"
                print(isSuccess)
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
    }
    @IBAction func click_Connect(_ sender : UIButton){
          if isConnct {
              self.btnConnect.isSelected = false
            lblStatus.text = "Disconnecting.."
            frekis!.disconnect(lock_id: self.txtLockID.text!)
            self.btnUnLock.isHidden = true
          }else{
            lblStatus.text = "Scanning.."
            frekis!.connect(lock_id: self.txtLockID.text!) { (isConnected,lock_id) in
                self.isConnct = isConnected
                self.get_lock_id = lock_id
                 self.lblStatus.text = "Asset connection \(isConnected ? "success.." : "failed..")"
                if isConnected {
                    self.isDeviceConnected = isConnected
    
                    self.btnConnect.isSelected = true
                    self.btnUnLock.isHidden = false
                }
                
            }
              
          }
      }
    @IBAction func click_UnLock(_ sender : UIButton){
         
                lblStatus.text = "Unlocking asset.."
                frekis!.unlockAsset(lock_id: self.get_lock_id, location: unlockLocation) { (unlockStatus) in
                        if unlockStatus {
                            self.btnUnLock.isHidden = true
                        }
                          self.lblStatus.text = "Asset unlock \(unlockStatus ? "success.." : "failed..")"
                        print("Device unlock status = ", unlockStatus)
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
            frekis!.connect(lock_id: self.txtLockID.text!) { (isConnected,lock_id) in
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
        frekis!.unlockAsset(lock_id: self.get_lock_id, location: unlockLocation) { (unlockStatus) in
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
    func deviceManuallyLocked() {
        lblStatus.text = "Locked"
               frekis!.lockAsset(lock_id: self.txtLockID.text!, location: lockLocation) { (lockStatus) in
                         print("Device lock status = ", lockStatus)
                if lockStatus {
                    DispatchQueue.main.async {
                        self.lblStatus.text = "Locked"
                        self.btnUnLock.isHidden = false
                    }
                    
                }
               }
    }
    
    func deviceDisconnected() {
        //handle disconnection..
        lblStatus.text = "Disconnected.."
    }
   
}
