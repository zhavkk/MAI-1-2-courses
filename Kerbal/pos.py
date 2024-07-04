import krpc

conn = krpc.connect(name='Vessel')
vessel = conn.space_center.active_vessel

flight_info = vessel.flight()
print(flight_info.mean_altitude)
refframe =vessel.orbit.body.reference_frame
print(vessel.position(reframe))
