[![N|Solid](https://secureservercdn.net/160.153.137.14/k8y.264.myftpupload.com/wp-content/uploads/2020/02/IMG_4910-295x300.jpeg)]()

Frekis SDK is iOS Framework which will help you to connect with the frekis account and manage your assets with in own app.

## Installation
[CocoaPods](https://cocoapods.org/) is a dependency manager for Cocoa projects. For usage and installation instructions, visit their website. To integrate Frekis into your Xcode project using CocoaPods, specify it in your Podfile:
```bash

  pod 'Frekis', '~> 0.0.4'
```
Include Frekis SDK dependency in to your Xcode project
```bash
    import FrekisFramework
```
## Usage
To **initialize** the sdk, Use below code and setListeners to receive the callback.
```Swift
//  Managed this instance class as a singleton class for further usage.
//  Recommended usages is to keep this instance in application class.
 var frekis : Frekis = Frekis.getInstance()
//  Set Delegate
frekis!.delegate = self
```
**Config** Configure the Frekis SDK with your Secret API key.
```Swift
frekis!.setAuthKey(token: { `SECRET_API_KEY`}) { (isSuccess) in

}
```
**Connection** is for Connect Ble device with Frekis SDK.
```Swift
frekis!.connect(lock_id: testLockID) { (isConnected,lock_id) in
    //Save this lock_id as CONNECTED_LOCK_ID for unlock assets 
}
```
**Unlock** and **lock** the asset - Make sure the frekis sdk is connected and asset is connected before calling this method.
Note, Client has to manually detect the status of lock and call this method once user is manually locking the device.
```Swift
// For Unlock Lock
let unlockLocation = CLLocationCoordinate2D(latitude: 23.082653, longitude: 72.524578)
//For Location need to always pass user current location
frekis!.unlockAsset(lock_id: CONNECTED_LOCK_ID, location: unlockLocation) { (unlockStatus) in

}

// For Update Lock Status
let lockLocation = CLLocationCoordinate2D(latitude: 23.070490, longitude: 72.522692)
//For Location need to always pass user current location
 frekis!.lockAsset(lock_id: CONNECTED_LOCK_ID, location: lockLocation) { (lockStatus) in
}
```
**Delegate** **Method** for uses like manually lock the lock and disconnect the lock.
```Swift
//This method get call when lock is discconeted from SDK or When unlocked
func deviceDisconnected(){
    
}

//This method get call when lock is manually locked by user.
func deviceManuallyLocked(){

}
```

