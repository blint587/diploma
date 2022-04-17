SET NOCOUNT ON
 
MERGE INTO [common].[MeasurementUnitTypes] AS Target
USING (VALUES
  ('Length','Length',1,0,0,0,0,0,0,1,1,0,'ohdp',1)
 ,('Mass','Mass',0,1,0,0,0,0,0,2,1,1,'ohdp',1)
 ,('Time','Time',0,0,1,0,0,0,0,3,1,2,'ohdp',1)
 ,('ElectricCurrent','Electric currency',0,0,0,1,0,0,0,4,1,3,'ohdp',1)
 ,('Temperature','Temperature',0,0,0,0,1,0,0,5,1,4,'ohdp',1)
 ,('AmountOfSubstance','Amount of substance',0,0,0,0,0,1,0,6,1,5,'ohdp',1)
 ,('LuminousIntensity','Luminous intensity',0,0,0,0,0,0,1,7,1,6,'ohdp',1)
 ,('Area','Area',2,0,0,0,0,0,0,21,0,7,'ohdp',1)
 ,('Volume','Volume',3,0,0,0,0,0,0,22,0,8,'ohdp',1)
 ,('VolumetricFlow','Volumetric flow',3,0,-1,0,0,0,0,25,0,9,'ohdp',1)
 ,('MolarConcentration','Molar concentration',-3,0,0,0,0,1,0,33,0,10,'ohdp',1)
 ,('Acceleration','Acceleration',1,0,-2,0,0,0,0,34,0,11,'ohdp',1)
 ,('Force','Force',1,1,-2,0,0,0,0,35,0,12,'ohdp',1)
 ,('Velocity','Velocity',1,0,-1,0,0,0,0,38,0,13,'ohdp',1)
 ,('Concentration','Concentration, Density',-3,1,0,0,0,0,0,41,0,14,'ohdp',1)
 ,('MassFlow','Mass flow',0,1,-1,0,0,0,0,46,0,15,'ohdp',1)
 ,('Pressure','Pressure',-1,1,-2,0,0,0,0,50,0,16,'ohdp',1)
 ,('DynamicViscosity','Dynamic viscosity',-1,1,-1,0,0,0,0,53,0,17,'ohdp',1)
 ,('KinematicViscosity','Kinematic viscosity',2,0,-1,0,0,0,0,54,0,18,'ohdp',1)
 ,('Power','Power',2,1,-3,0,0,0,0,55,0,19,'ohdp',1)
 ,('Energy','Energy, Torque',2,1,-2,0,0,0,0,57,0,20,'ohdp',1)
 ,('Voltage','Voltage',2,1,-2,-1,0,0,0,58,0,21,'ohdp',1)
 ,('Frequency','Frequency, Radioactivity',0,0,-1,0,0,0,0,59,0,22,'ohdp',1)
 ,('ElectricCharge','Electric charge',0,0,1,1,0,0,0,61,0,23,'ohdp',1)
 ,('ElectricCapacitance','Electric capacitance',-2,-1,4,2,0,0,0,62,0,24,'ohdp',1)
 ,('ElectricResistance','Electric resistance',2,1,-3,-2,0,0,0,63,0,25,'ohdp',1)
 ,('ElectricalConductance','Electrical conductance',-2,-1,3,2,0,0,0,64,0,26,'ohdp',1)
 ,('MagneticFlux','Magnetic flux',2,1,-2,-1,0,0,0,65,0,27,'ohdp',1)
 ,('MagneticFluxDensity','Magnetic flux density',0,1,-2,-1,0,0,0,66,0,28,'ohdp',1)
 ,('Inductance','Inductance',2,1,-2,-2,0,0,0,67,0,29,'ohdp',1)
 ,('Illuminance','Illuminance',-2,0,0,0,0,0,1,68,0,30,'ohdp',1)
 ,('AbsorbedDose','Absorbed dose',2,0,-2,0,0,0,0,69,0,31,'ohdp',1)
 ,('CatalyticActivity','Catalytic activity',0,0,-1,0,0,1,0,70,0,32,'ohdp',1)
 ,('MolarWeight','Molar weight',0,1,0,0,0,-1,0,71,0,33,'ohdp',1)
 ,('EnergyFlux','Energy Flux',0,1,-3,0,0,0,0,87,0,34,'bmolnar',1)
 ,('EnergyPerArea','Energy per Area',0,1,-2,0,0,0,0,88,0,35,'bmolnar',1)
 ,('MassFlux','Mass flux',-2,1,-1,0,0,0,0,89,0,36,'bmolnar',1)
 ,('AreaDensity','Area density',-2,1,0,0,0,0,0,91,0,37,'bmolnar',1)
 ,('None','None',0,0,0,0,0,0,0,NULL,0,100,'ohdp',1)
) AS Source ([Name],[Description],[DLength],[DMass],[DTime],[DElectricCurrent],[DTemperature],[DAmountOfSubstance],[DLuminousIntensity],[BaseUnitId],[BaseType],[Id],[User],[IsValid])
ON (Target.[Id] = Source.[Id])
WHEN MATCHED AND (Target.[Name] <> Source.[Name] OR Target.[Description] <> Source.[Description] OR Target.[DLength] <> Source.[DLength] OR Target.[DMass] <> Source.[DMass] OR Target.[DTime] <> Source.[DTime] OR Target.[DElectricCurrent] <> Source.[DElectricCurrent] OR Target.[DTemperature] <> Source.[DTemperature] OR Target.[DAmountOfSubstance] <> Source.[DAmountOfSubstance] OR Target.[DLuminousIntensity] <> Source.[DLuminousIntensity] OR Target.[BaseUnitId] <> Source.[BaseUnitId] OR Target.[BaseType] <> Source.[BaseType] OR Target.[User] <> Source.[User] OR Target.[IsValid] <> Source.[IsValid]) THEN
 UPDATE SET
 [Name] = Source.[Name], 
[Description] = Source.[Description], 
[DLength] = Source.[DLength], 
[DMass] = Source.[DMass], 
[DTime] = Source.[DTime], 
[DElectricCurrent] = Source.[DElectricCurrent],
[DTemperature] = Source.[DTemperature], 
[DAmountOfSubstance] = Source.[DAmountOfSubstance], 
[DLuminousIntensity] = Source.[DLuminousIntensity], 
[BaseUnitId] = Source.[BaseUnitId], 
[BaseType] = Source.[BaseType],
[User] = Source.[User],
[IsValid] = Source.[IsValid]
WHEN NOT MATCHED BY TARGET THEN
 INSERT([Name],[Description],[DLength],[DMass],[DTime],[DElectricCurrent],[DTemperature],[DAmountOfSubstance],[DLuminousIntensity],[BaseUnitId],[BaseType],[Id],[User],[IsValid])
 VALUES(Source.[Name],Source.[Description],Source.[DLength],Source.[DMass],Source.[DTime],Source.[DElectricCurrent],Source.[DTemperature],Source.[DAmountOfSubstance],Source.[DLuminousIntensity],Source.[BaseUnitId],Source.[BaseType],Source.[Id],Source.[User],Source.[IsValid])
WHEN NOT MATCHED BY SOURCE THEN 
 DELETE;
 
GO
DECLARE @mergeError int
 , @mergeCount int
SELECT @mergeError = @@ERROR, @mergeCount = @@ROWCOUNT
IF @mergeError != 0
 BEGIN
 PRINT 'ERROR OCCURRED IN MERGE FOR [common].[MeasurementUnitTypes]. Rows affected: ' + CAST(@mergeCount AS VARCHAR(100)); -- SQL should always return zero rows affected
 END
ELSE
 BEGIN
 PRINT '[common].[MeasurementUnitTypes] rows affected by MERGE: ' + CAST(@mergeCount AS VARCHAR(100));
 END
GO
 
SET NOCOUNT OFF
GO
 
 