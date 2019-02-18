using munitscs;
using NUnit.Framework;

namespace munitscs_utests
{
    [TestFixture]
    public class TestRepresentation
    {       
        [Test]
        public void test_mass(){
            Quantity m1 = new Quantity(Metrics.Mass, 1, "kg");
        
            string s = (string) m1;
        
            Assert.AreEqual("1 kg", s);
        
        }
        [Test]
        public void test_time(){
            Quantity t1 = new Quantity(Metrics.Time, 1, "s");
        
            string s = (string) t1;
        
            Assert.AreEqual("1 s", s);
        
        }
        
        [Test]
        public void test_legth(){
            Quantity l1 = new Quantity(Metrics.Length, 1, "inc");
        
            string s = (string) l1;
        
            Assert.AreEqual("1 inc", s);
        
        }
        
        [Test]
        public void test_temperature(){
            Quantity l1 = new Quantity(Metrics.Temperature, 1, "°C");
        
            string s = (string) l1;
        
            Assert.AreEqual("1 °C", s);
        
        }
        [Test]
        public void test_amount_of_substance(){
            Quantity l1 = new Quantity(Metrics.AmountOfSubstance, 1, "mol");
        
            string s = (string) l1;
        
            Assert.AreEqual("1 mol", s);
        
        }
        
        [Test]
        public void test_velocity_direct_creation(){
            Quantity l1 = new Quantity(Metrics.Velocity, 1, "m s-1");
        
            string s = (string) l1;
        
            Assert.AreEqual("1 m s-1", s);
        
        }
        
        [Test]
        public void test_velocity_indirect_creation(){
            Quantity l1 = new Quantity(Metrics.Length, 1, "m");
            Quantity t1 = new Quantity(Metrics.Time, 1, "s");
        
            var v1 = l1 / t1;
        
            string s = (string) v1;
        
            Assert.AreEqual("1 m s-1", s);
        
        }
        
        [Test]
        public void test_force_direct_creation(){
            Quantity f = new Quantity(Metrics.Force, 1, "kg m s-2");
        
        
            string s = (string) f;
        
            Assert.AreEqual("1 N", s); // should be represented as N
        
        }
        [Test]
        public void test_force_indirect_creation(){
            Quantity a = new Quantity(Metrics.Acceleration, 1, "m s-2");
            Quantity m = new Quantity(Metrics.Mass, 1, "kg");
        
            var f = m * a;
        
            string s = (string) f;
        
            Assert.AreEqual("1 N", s); // should be represented as N
        
        }
        [Test]
        public void test_mass_flow_indirect_creation(){
            Quantity q = new Quantity(Metrics.VolumetricFlow, 1, "m3 h-1");
            Quantity c = new Quantity(Metrics.Concentration, 1, "g l-1");
        
            var mdot = q * c;
        
            string s = (string) mdot;
        
            Assert.AreEqual("1000 g h-1", s); // should be represented as N
        
        }

    }
}