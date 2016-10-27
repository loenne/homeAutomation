# file: logger.py
import td
import time
def logSensorEvent(protocol, model, id, dataType, value, timestamp, callbackId):
    # print a line for each event with time, sensor id, data type, value, protocoll, and model
    print '%s,%d,%d,%s,%s,%s' %(time.strftime("%Y-%m-%d,%H:%M:%S"), id, dataType, value, protocol, model)
if __name__ == '__main__':
    # Intialize the communcation
    td.init( defaultMethods = td.TELLSTICK_TURNON | td.TELLSTICK_TURNOFF )
    # Register callbacks
    callbackId = []
    callbackId.append(td.registerSensorEvent(logSensorEvent))
    # Run infinite loop
    try:
        while(1):
            time.sleep(1)
    except KeyboardInterrupt:
        for i in callbackId:
            # De-register callbacks
            td.unregisterCallback(i)
    # Close communication so telldus-core can do some cleanup.
    td.close()
## End logger.py

